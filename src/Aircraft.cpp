/*
 * Aircraft.c++
 *
 *  Created on: Oct. 25, 2022
 *      Author: coen320
 */
class Aircraft {
public:
    Aircraft(int x_coor, int y_coor, int z_coor) {
        this->x_coor = x_coor;
        this->y_coor = y_coor;
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