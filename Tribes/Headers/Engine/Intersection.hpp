/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Intersection.h
 *  ShaderToy
 *
 *  Created by ryan needham on 18/08/2016.
 *  Copyright © 2016 Personal Project. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Intersection_hpp
#define Intersection_hpp

class Intersection {
public:
    Intersection (const bool intersecting, const float distance) {
        this->intersecting = intersecting;
        this->distance = distance;
    }
    
    bool  isIntersecting () { return intersecting; }
    float getDistance    () { return distance; }
    
private:
    bool  intersecting;
    float distance;
};

#endif /* Intersection_hpp */
