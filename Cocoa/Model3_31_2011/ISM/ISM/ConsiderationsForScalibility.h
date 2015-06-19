//
// MICAH's Union Example

#ifndef ISM_Header_h
#define ISM_Header_h


struct Normal {
    union {
        struct {
            double x, y, z;
        };
        double v[3];
    };
};



#endif