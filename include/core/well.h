#pragma once

#include "cinder/gl/gl.h"

namespace finalproject {

/**
 * Class that represents the well in simulation (if I have time, this will be split into InfiniteWell and FiniteWell classes)
 */
class Well {
public:
    /**
     * Default constructor of Well class
     * @param start_pos The starting x-position of the well
     * @param end_pos The ending x-position of the well
     */
    Well(double start_pos, double end_pos);

    /**
     * Copy constructor of Well class
     * @param well The well whose values we want to copy into this instance
     */
    Well(const Well& well);

    /**
     * Gets the starting position of the well
     * @return The value of the start_pos_ variable
     */
    double GetStartPos() const;

    /**
     * Gets the ending position of the well
     * @return The value of the end_pos_ variable
     */
    double GetEndPos() const;

    /**
     * Gets the length of the well
     * @return The value of the length_ variable
     */
    double GetLength() const;

    /**
     * Sets value of start_pos_ variable
     * @param start_pos The value we want to set the starting position of this well to
     */
    void SetStartPos(double start_pos);

    /**
     * Sets value of end_pos_ variable
     * @param end_pos The value we want to set the ending position of this well to
     */
    void SetEndPos(double end_pos);
private:
    double start_pos_; //starting x-pos of the well
    double end_pos_; //ending x-pos of the well
    double length_; //length of the well
};

}
