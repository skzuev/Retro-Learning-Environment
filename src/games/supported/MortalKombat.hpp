/* *****************************************************************************
 * The line 67 is based on Xitari's code, from Google Inc.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 * *****************************************************************************
 * A.L.E (Arcade Learning Environment)
 * Copyright (c) 2009-2013 by Yavar Naddaf, Joel Veness, Marc G. Bellemare and
 *   the Reinforcement Learning and Artificial Intelligence Laboratory
 * Released under the GNU General Public License; see License.txt for details.
 *
 * Based on: Stella  --  "An Atari 2600 VCS Emulator"
 * Copyright (c) 1995-2007 by Bradford W. Mott and the Stella team
 *
 * *****************************************************************************
 */

#ifndef __MORTAL_KOMBAT_SETTINGS_HPP__
#define __MORTAL_KOMBAT_SETTINGS_HPP__
/* RL wrapper for AtariCollection settings */

#include "../SnesSettings.hpp"
#include <unordered_set>

namespace rle {

struct MortalKombatSettings : public SnesSettings {

    public:

		MortalKombatSettings();

        // reset
        virtual void reset();

        // is end of game
        virtual bool isTerminal() const;

        // get the most recently observed reward
        virtual reward_t getReward() const;

        // the rom-name
        virtual const char* rom() const { return "mortal_kombat"; }

        // create a new instance of the rom
        virtual RomSettings* clone() const;

        // is an action part of the minimal set?
        virtual bool isMinimal(const Action& a) const;

        // process the latest information from ALE
        virtual void step(const RleSystem& system);

        // saves the state of the rom settings
        virtual void saveState( Serializer & ser );

        // loads the state of the rom settings
        virtual void loadState( Deserializer & des );

        virtual const int lives() { return 0; }

        virtual ActionVect getStartingActions(const RleSystem& system);

        void startingOperations(RleSystem& system);

    protected:
        std::unordered_set<Action> minimalActions;
        bool m_terminal;
        reward_t m_reward;
        reward_t m_score;
        int m_wins;
        int o_wins;
        bool match_ended;
};

} // namespace rle

#endif // __MORTAL_KOMBAT_SETTINGS_HPP__
