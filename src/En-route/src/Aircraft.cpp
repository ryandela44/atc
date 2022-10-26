/*
 * Aircraft.c++
 *
 *  Created on: Oct. 25, 2022
 *      Author: coen320
 */
class Aircraft {
public:
    Aircraft() {

    }
    void set_x_coor(int x_coor) {
        this->x_coor = x_coor;
    }

    void set_y_coor(int y_coor) {
        this->y_coor = y_coor;
    }

    void set_z_coor(int z_coor) {
        this->z_coor = z_coor;
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

private:
    int x_coor;
    int y_coor;
    int z_coor;
};