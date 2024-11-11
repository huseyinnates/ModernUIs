#pragma once

#include "lve_descriptors.hpp"
#include "lve_device.hpp"
#include "lve_game_object.hpp"
#include "lve_renderer.hpp"
#include "lve_window.hpp"

// std
#include <memory>
#include <vector>

namespace Wallnut {
class FirstApp {
 public:
  static constexpr int WIDTH = 800;
  static constexpr int HEIGHT = 600;

  FirstApp();
  ~FirstApp();
  int Counter = 0;
  FirstApp(const FirstApp &) = delete;
  FirstApp &operator=(const FirstApp &) = delete; 
  void run();

 private:
  void loadGameObjects();

  lve::LveWindow lveWindow{WIDTH, HEIGHT, "Vulkan Tutorial"};
  lve::LveDevice lveDevice{lveWindow};
  lve::LveRenderer lveRenderer{lveWindow, lveDevice};

  // note: order of declarations matters
  std::unique_ptr<lve::LveDescriptorPool> globalPool{};
  lve::LveGameObject::Map gameObjects;
};
}  // namespace lve
