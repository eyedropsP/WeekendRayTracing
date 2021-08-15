#ifndef METAL_H
#define METAL_H

#include "material.h"
#include "color.h"
#include "hittable.h"

class metal : public material {
public:
    metal(const color &a) : albedo(a) {}

    virtual bool scatter(const ray &r_in, const hit_record &record, color &attenuation, ray &scattered) const {
        vec3 reflected = reflect(unit_vector(r_in.direction()), record.normal);
        scattered = ray(record.p, reflected);
        attenuation = albedo;
        return (dot(scattered.direction(), record.normal) > 0);
    }

public:
    color albedo;
};

#endif //METAL_H
