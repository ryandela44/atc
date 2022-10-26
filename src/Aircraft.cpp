/*
 * Aircraft.c++
 *
 *  Created on: Oct. 25, 2022
 *      Author: coen320
 */
class Aircraft {
public:
    Aircraft(int id, int x_coor, int y_coor, int flight_level, int speed) {
        this->id = id;
        this->x_coor = x_coor;
        this->y_coor = y_coor;
        this->flight_level = flight_level;
        this->speed = speed;
    }

    int get_id() {
        return id;
    }

    int get_x_coor() {
        return x_coor;
    }

    int get_y_coor() {
        return y_coor;
    }

    int get_flight_level() {
        return flight_level;
    }

    int get_speed() {
        return speed;
    }

private:
    int id;
    int x_coor;
    int y_coor;
    int flight_level;
    int speed;
};