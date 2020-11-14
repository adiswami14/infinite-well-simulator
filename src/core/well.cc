#include <core/well.h>

namespace finalproject {

Well::Well(double start_pos, double end_pos) : start_pos_(start_pos), end_pos_(end_pos){
    if(end_pos_<=start_pos_) {
        throw std::invalid_argument("Wall's ending position must be greater than it's starting position!");
    }
    length_ = end_pos_ - start_pos_;
}

Well::Well(const Well &well) {
    end_pos_ = well.end_pos_;
    start_pos_ = well.start_pos_;
    length_ = well.length_;
}

double Well::GetEndPos() const {
    return end_pos_;
}

double Well::GetLength() const {
    return length_;
}

double Well::GetStartPos() const {
    return start_pos_;
}

void Well::SetEndPos(double end_pos) {
    if(end_pos <= start_pos_) {
        return;
    }
    end_pos_ = end_pos;
    length_ = end_pos_ - start_pos_;
}

void Well::SetStartPos(double start_pos) {
    if(start_pos>=end_pos_) {
        return;
    }
    start_pos_ = start_pos;
    length_ = end_pos_ - start_pos_;
}

}