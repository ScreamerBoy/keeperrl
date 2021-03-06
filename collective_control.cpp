#include "stdafx.h"
#include "collective_control.h"
#include "collective.h"
#include "attack_trigger.h"

template <class Archive>
void CollectiveControl::serialize(Archive& ar, const unsigned int version) {
  ar & SVAR(collective);
}

SERIALIZABLE(CollectiveControl);
SERIALIZATION_CONSTRUCTOR_IMPL(CollectiveControl);

CollectiveControl::CollectiveControl(Collective* c) : collective(c) {
}

Collective* CollectiveControl::getCollective() const {
  return NOTNULL(collective);
}

void CollectiveControl::update(bool currentlyActive) {
}

void CollectiveControl::tick() {
}

const vector<Creature*>& CollectiveControl::getCreatures() const {
  return getCollective()->getCreatures();
}

void CollectiveControl::onMemberKilled(const Creature* victim, const Creature* killer) {
}

void CollectiveControl::onOtherKilled(const Creature* victim, const Creature* killer) {
}

CollectiveControl::~CollectiveControl() {
}

class IdleControl : public CollectiveControl {
  public:

  using CollectiveControl::CollectiveControl;

  virtual void tick() override {
  }

  SERIALIZATION_CONSTRUCTOR(IdleControl);
  
  template <class Archive>
  void serialize(Archive& ar, const unsigned int version) {
    ar & SUBCLASS(CollectiveControl);
  }
};

vector<TriggerInfo> CollectiveControl::getTriggers(const Collective* against) const {
  return {};
}

PCollectiveControl CollectiveControl::idle(Collective* col) {
  return PCollectiveControl(new IdleControl(col));
}

template <class Archive>
void CollectiveControl::registerTypes(Archive& ar, int version) {
  REGISTER_TYPE(ar, IdleControl);
}

REGISTER_TYPES(CollectiveControl::registerTypes);

