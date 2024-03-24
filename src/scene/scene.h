#pragma once

#include <vector>

#include "camera.h"
#include "light.h"
#include "objects/sphere.h"

class Scene
{
public:
    explicit Scene(const Camera& camera)
        : camera_(camera)
    {}

    void add_light(const Light& light)
    {
        this->lights_.push_back(light);
    }

    void add_object(const Sphere& object)
    {
        this->objects_.push_back(object);
    }

    void draw_scene(int width, int height) const
    {
        this->camera_.shoot_rays(width, height, this->objects_);
    }

private:
    Camera camera_;
    std::vector<Light> lights_;
    // TODO: Change this to a vector of objects
    std::vector<Sphere> objects_;
};
