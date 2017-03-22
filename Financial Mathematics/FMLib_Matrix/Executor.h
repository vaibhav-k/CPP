#ifndef EXECUTOR_H_INCLUDED
#define EXECUTOR_H_INCLUDED

#pragma once

#include "stdafx.h"
#include "Task.h"

/*  An executor will execute tasks on mutliple threads */
class Executor {
public:
    /*  Destructor */
    virtual ~Executor() {}
    /*  Add a task to the executor */
    virtual void addTask(
        std::shared_ptr<Task> task ) = 0;
    /*  Wait until all tasks are complete */
    virtual void join() = 0;
    /*  Factory method */
    static std::shared_ptr<Executor> newInstance();
    /*  Factory method */
    static std::shared_ptr<Executor> newInstance(
        int maxThreads );
};

typedef std::shared_ptr<Executor> SPExecutor;

/*  Test method */
void testExecutor();

#endif // EXECUTOR_H_INCLUDED
