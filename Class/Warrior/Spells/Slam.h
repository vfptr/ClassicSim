#pragma once

#include <QVector>

#include "CastingTimeRequirer.h"
#include "Spell.h"
#include "TalentRequirer.h"

class Warrior;
class WarriorSpells;

class Slam: public Spell, public CastingTimeRequirer, public TalentRequirer {
public:
    Slam(Warrior* pchar, WarriorSpells* spells);
    ~Slam() override;

private:
    Warrior* warr;
    WarriorSpells* spells;
    const QVector<unsigned> talent_ranks;

    void spell_effect() override;
    void complete_cast_effect() override;
    SpellStatus is_ready_spell_specific() const override;

    void increase_talent_rank_effect(const QString& talent_name, const int curr) override;
    void decrease_talent_rank_effect(const QString& talent_name, const int curr) override;
};
