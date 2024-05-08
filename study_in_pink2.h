/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2023
* Author: Vu Van Tien
* Date: 02.02.2023
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef _H_STUDY_IN_PINK_2_H_
#define _H_STUDY_IN_PINK_2_H_

#include "main.h"

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

// Forward declaration
// class MovingObject;
// class Position;
// class Configuration;
// class Map;

// class Criminal;
// class RobotS;
// class RobotW;
// class RobotSW;
// class RobotC;

// class ArrayMovingObject;
// class StudyPinkProgram;

// class BaseItem;
// class BaseBag;
// class SherlockBag;
// class WatsonBag;

class TestStudyInPink;

enum ItemType { MAGIC_BOOK, ENERGY_DRINK, FIRST_AID, EXCEMPTION_CARD, PASSING_CARD };
enum ElementType { PATH, WALL, FAKE_WALL };
enum RobotType { C=0, S, W, SW };

class MapElement {
protected:
    ElementType type;
    int r;
    int c;
public:
    MapElement(ElementType in_type){
        type = in_type;
    };
    virtual ~MapElement(){};
    virtual ElementType getType() const{
        return type;
    };
};

class Path : public MapElement {
    public:
    Path(): MapElement(PATH){}
};

class Wall : public MapElement {
    public:
    Wall():MapElement(WALL){}
};

class FakeWall : public MapElement {
    private:
        int req_exp;
    public:
        FakeWall(int in_req_exp): MapElement(FAKE_WALL), req_exp(in_req_exp){
            in_req_exp = ( r *257 + c*139+89)%900 + 1;
        }
        int getRepExp() const{
            return req_exp;
        }
};

class Map {
private:
    int num_rows, num_cols;
    MapElement*** map;
public:
    Map(int num_rows, int num_cols, int num_walls, Position * array_walls, int num_fake_walls, Position * array_fake_walls) : num_rows(num_rows), num_cols(num_cols){};
    ~Map(){};
    bool isValid ( const Position & pos , MovingObject * mv_obj ) const{} ;
};

class Position {
private:
    int r, c;
public:
    static const Position npos;

    Position(int r=0, int c=0){};

    Position(const string & str_pos){};

    int getRow() const{
        return r;
    };
    int getCol() const{
        return c;
    };
    void setRow(int r){
        this->r = r;
    };
    void setCol(int c){
        this->c = c;
    };

    string str() const{
        return "(" + to_string(r) + "," + to_string(c) +")";
    };

    bool isEqual(int in_r, int in_c) const{
        if ( in_r ==  r && in_c == c) {
            return true;
        }else return false;
    };
};

class MovingObject {
protected:
    int index;
    Position pos;
    Map * map;
    string name;

public:
    MovingObject(int index, const Position pos, Map * map, const string & name=""){
        this->index = index;
        this->pos = pos;
        this->map = map;
    };
    virtual ~MovingObject(){};
    virtual Position getNextPosition() = 0;
    Position getCurrentPosition() const{
        return pos;
    };
    virtual void move() = 0;
    virtual string str() const = 0;
};

class Sherlock: public MovingObject /* TODO */ {
private:
    // TODO
    int hp;
    int exp;
    string moving_rule;
public:
    Sherlock(int index, const string & moving_rule, const Position & init_pos, Map * map, int init_hp, int init_exp)
    :MovingObject(index, init_pos,map,"Sherlock"), hp(init_hp),exp(init_exp),moving_rule(moving_rule){
        if ( hp > 500) hp = 500;
        if ( hp <= 0) hp = 0;
        if ( exp > 900) exp = 900;
        if ( exp <= 0) exp = 0;
    };
    Position getNextPosition(){
        static int c_index = 0;
        char a = moving_rule[c_index++];
        if (c_index == moving_rule.length()){
            c_index = 0;
        }
        Position next_pos = getCurrentPosition();
        if ( a == 'L'){
            next_pos.setCol(next_pos.getCol()-1);
        }
        if ( a == 'R'){
            next_pos.setCol(next_pos.getCol() +1);
        }
        if (a == 'U'){
            next_pos.setRow(next_pos.getRow()+1);
        }
        if ( a == 'D'){
            next_pos.setCol(next_pos.getRow()-1);
        }
        if ( map->isValid(next_pos, this)){
            return next_pos;
        }else return Position::npos;
        
    }
    void move(){
        Position next_pos = getNextPosition();
        if ( next_pos != Position::npos ){
            pos =  next_pos;
        }
    }
    string str(){
        return "Sherlock[index=" + to_string(index) + ";" + "pos=" + to_string(pos) + ";moving_rule=" + moving_rule +"]";
    }
    // ...
};

class Watson: public MovingObject /* TODO */ {
private:
    // TODO
    int hp;
    int exp;
    string moving_rule;
public:
    Watson(int index, const string & moving_rule, const Position & init_pos, Map * map, int init_hp, int init_exp)
    :MovingObject(index, init_pos,map,"Watson"), hp(init_hp),exp(init_exp),moving_rule(moving_rule){
        if ( hp > 500) hp = 500;
        if ( hp <= 0) hp = 0;
        if ( exp > 900) exp = 900;
        if ( exp <= 0) exp = 0;
    };
    Position getNextPosition(){
        static int c_index = 0;
        char a = moving_rule[c_index++];
        if (c_index == moving_rule.length()){
            c_index = 0;
        }
        Position next_pos = getCurrentPosition();
        if ( a == 'L'){
            next_pos.setCol(next_pos.getCol()-1);
        }
        if ( a == 'R'){
            next_pos.setCol(next_pos.getCol() +1);
        }
        if (a == 'U'){
            next_pos.setRow(next_pos.getRow()+1);
        }
        if ( a == 'D'){
            next_pos.setCol(next_pos.getRow()-1);
        }
        if ( map->isValid(next_pos, this)){
            return next_pos;
        }else return Position::npos;
        
    }
    void move(){
        Position next_pos = getNextPosition();
        if ( next_pos != Position::npos ){
            pos =  next_pos;
        }
    }
    string str(){
        return "Watson[index=" + to_string(index) + ";" + "pos=" + to_string(pos) + ";moving_rule=" + moving_rule +"]";
    }
    // getNextPosition
    // move
    // str
    // ...
};
int Manhattan(Position p1, Position p2){
    return abs(p1.getRow()-p2.getRow()) + abs(p1.getCol()-p2.getCol());
}
class Criminal:public MovingObject /* TODO */ {
private:
    // TODO
    
public:
    Criminal(int index, const Position & init_pos, Map * map, Sherlock * sherlock, Watson * watson)
    :MovingObject(index, pos, map,"Criminal"){};
    Position getNextPosition(){
        // move U
        Position next_pos_U;
        next_pos_U.setRow(init_pos.getRow()+1);
        next_pos_U.setCol(inti_pos.getCol())
        int d_U = Manhattan(next_pos_U, sherlock.getNextPosition())
    }
    void move(){
        Position next_pos = getNextPosition();
        if ( next_pos != Position::npos ){
            pos =  next_pos;
        }
    }
    string str(){
        return "Criminal[index=" + to_string(index) + ";" + "pos=" + to_string(pos)+"]";
    }
    
    // ...
};

class ArrayMovingObject {
private:
    // TODO

public:
    ArrayMovingObject(int capacity);

    ~ArrayMovingObject() ;
    bool isFull() const;
    bool add(MovingObject * mv_obj);
    MovingObject * get(int index) const;
    int size() const; // return current number of elements in the array
    string str() const;
};

class Configuration {
    friend class StudyPinkProgram;

private:
    // TODO

public:
    Configuration(const string & filepath);
    ~Configuration();
    string str() const;
};

// Robot, BaseItem, BaseBag,...

class StudyPinkProgram {
private:
    // Sample attributes
    Configuration * config;
    
    Sherlock * sherlock;
    Watson * watson;
    Criminal * criminal;
    
    Map * map;
    ArrayMovingObject * arr_mv_objs;


public:
    StudyPinkProgram(const string & config_file_path);

    bool isStop() const;

    void printResult() const {
        if (sherlock->getCurrentPosition().isEqual(criminal->getCurrentPosition())) {
            cout << "Sherlock caught the criminal" << endl;
        }
        else if (watson->getCurrentPosition().isEqual(criminal->getCurrentPosition())) {
            cout << "Watson caught the criminal" << endl;
        }
        else {
            cout << "The criminal escaped" << endl;
        }
    }

    void printStep(int si) const {
        cout << "Step: " << setw(4) << setfill('0') << si
            << "--"
            << sherlock->str() << "--|--" << watson->str() << "--|--" << criminal->str() << endl;
    }

    void run(bool verbose) {
        // Note: This is a sample code. You can change the implementation as you like.
        // TODO
        for (int istep = 0; istep < config->num_steps; ++istep) {
            for (int i = 0; i < arr_mv_objs->size(); ++i) {
                arr_mv_objs->get(i)->move();
                if (isStop()) {
                    printStep(istep);
                    break;
                }
                if (verbose) {
                    printStep(istep);
                }
            }
        }
        printResult();
    }

    ~StudyPinkProgram();
};

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_2_H_ */