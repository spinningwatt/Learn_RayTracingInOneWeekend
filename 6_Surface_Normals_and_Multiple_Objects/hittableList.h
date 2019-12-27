#ifndef HITTALBELISTH
#define HITTABLELISTH

#include "hittable.h"

class hittable_list: public hittable
{
    public:
    hittable **list;
    int list_size;
    
    hittable_list(){};
    hittable_list(hittable **lst, int n)
    {
        list = lst;
        list_size = n;
    };
    virtual bool hit(const ray& r, float tmin, float tmax, hit_record& rec) const;
};

bool hittable_list::hit(const ray& r, float tmin, float tmax, hit_record& rec) const
{
    hit_record temp_rec;
    bool hit_anything = false;
    double closet_so_far = tmax;
    for(int i=0; i<list_size; i++)
    {
        if(list[i]->hit(r, tmin, closet_so_far, temp_rec))
        {
            hit_anything = true;
            closet_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }
    return hit_anything;
};

#endif