#ifndef METAL_H
#define METAL_H

#include "material.h"
#include "color.h"
#include "hittable.h"

class metal : public material {
public:
    explicit metal(const color &a, double f) : albedo(a), fuzz(f < 1 ? f : 1) {}

    bool scatter(const ray &r_in, const hit_record &record, color &attenuation, ray &scattered) const override {
        vec3 reflected = reflect(unit_vector(r_in.direction()), record.normal);
        scattered = ray(record.p, reflected + fuzz * random_in_unit_sphere());
        attenuation = albedo;
        return (dot(scattered.direction(), record.normal) > 0);
    }

public:
    color albedo;
    double fuzz;
};

#endif //METAL_H
