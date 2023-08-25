#pragma once

#include <memory>
#include <stack>

#include "state.hpp"

namespace tetris
{
    typedef std::unique_ptr<State> StateRef;

    class StateMachine
    {
    public:
        StateMachine() {}
        ~StateMachine() {}

        void addState(StateRef newState, bool isReplacing = true);
        void removeState();
        // Run at start of each loop in Game.cpp
        void processStateChanges();

        StateRef &getActiveState();

    private:
        std::stack<StateRef> _states;
        StateRef _newState;

        bool _isRemoving;
        bool _isAdding, _isReplacing;
    };
}

 // STATE_MACHINE_HPP
