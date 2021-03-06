#pragma once

#include "TestSpellRogue.h"

class AdrenalineRush;

class TestAdrenalineRush: public TestSpellRogue {
public:
    TestAdrenalineRush(EquipmentDb *equipment_db);

    void test_all();

private:
    AdrenalineRush* adrenaline_rush() const;

    void test_name_correct() override;
    void test_spell_cooldown() override;
    void test_whether_spell_causes_global_cooldown() override;
    void test_how_spell_observes_global_cooldown() override;
    void test_resource_cost() override;
    void test_is_ready_conditions() override;
    void test_combo_points() override;
    void test_stealth() override;

    void test_tick_rate_over_entire_duration();

    void when_adrenaline_rush_is_performed();

    void given_1_of_1_adrenaline_rush();
};
