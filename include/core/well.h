#pragma once

#include "cinder/gl/gl.h"

namespace finalproject {

class Well {
public:
    Well(double start_pos, double end_pos);

    Well(const Well& well);

    double GetStartPos() const;

    double GetEndPos() const;

    double GetLength() const;

    void SetStartPos(double start_pos);

    void SetEndPos(double end_pos);
private:
    double start_pos_;
    double end_pos_;
    double length_;
};

}
