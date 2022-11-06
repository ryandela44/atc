/*
 * Aircraft.c++
 *
 *  Created on: Oct. 25, 2022
 *      Author: coen320
 */
class Aircraft {
public:
    Aircraft(int id, int x_coor, int y_coor, int z_coor, int x_speed,int y_speed,int z_speed) {
        this->id = id;
        this->x_coor = x_coor;
        this->y_coor = y_coor;
        this->z_coor = z_coor;
        this->x_speed = x_speed;
        this->y_speed = y_speed;
        this->z_speed = z_speed;
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

    int get_z_coor() {
        return z_coor;
    }

    int get_x_speed() {
        return x_speed;
    }

    int get_y_speed() {
        return y_speed;
    }

    int get_z_speed() {
        return z_speed;
    }

private:
    int id;
    int x_coor;
    int y_coor;
    int z_coor;
    int x_speed;
    int y_speed;
    int z_speed;
};
