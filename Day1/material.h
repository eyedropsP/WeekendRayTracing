#ifndef MATERIAL_H
#define MATERIAL_H

class material {
public:
    virtual ~material() = default;

    virtual bool scatter(const ray &r_in, const hit_record &rec, color &attenuation, ray &scattered) const = 0;
};

#endif //MATERIAL_H
