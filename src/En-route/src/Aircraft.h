#pragma once

class Airspace {
public:
private:
    int x_coor;
    int y_coor;
    int z_coor;
    void set_x_coor(int x_coor);
    void set_y_coor(int y_coor);
    void set_z_coor(int z_coor);
public:
    int get_x_coor();
    int get_y_coor();
    int get_z_coor();
};