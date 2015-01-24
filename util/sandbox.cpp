#include <iostream>

#include "yaml-cpp/emitterstyle.h"
#include "yaml-cpp/eventhandler.h"
#include "yaml-cpp/yaml.h"  // IWYU pragma: keep

class NullEventHandler : public YAML::EventHandler {
 public:
  typedef YAML::Mark Mark;
  typedef YAML::anchor_t anchor_t;

  NullEventHandler() {}

  virtual void OnDocumentStart(const Mark&) {}
  virtual void OnDocumentEnd() {}
  virtual void OnNull(const Mark&, anchor_t) {}
  virtual void OnAlias(const Mark&, anchor_t) {}
  virtual void OnScalar(const Mark&, const std::string&, anchor_t,
                        const std::string&) {}
  virtual void OnSequenceStart(const Mark&, const std::string&, anchor_t,
                               YAML::EmitterStyle::value style) {}
  virtual void OnSequenceEnd() {}
  virtual void OnMapStart(const Mark&, const std::string&, anchor_t,
                          YAML::EmitterStyle::value style) {}
  virtual void OnMapEnd() {}
};

int main() {
  const YAML::Node node;

  std::string key = "doesnotexist";
  for (;;) {
    node[key];
  }
  return 0;
}
