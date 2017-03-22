#ifndef TASK_H_INCLUDED
#define TASK_H_INCLUDED

#pragma once

#include "stdafx.h"

/**
 *   A task is simply something with an execute
 *   method.
 */
class Task {
public:
    virtual ~Task() {}
    virtual void execute() = 0;
};

#endif // TASK_H_INCLUDED
