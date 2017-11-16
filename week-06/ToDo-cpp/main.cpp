/*           TODO APPLICATION in C++
 * ============================================
 * Greenfox Academy Pallida Cohort Static Class
 *               András Pásztor
 */

#include <iostream>
#include <string>
#include "define.h"
#include "ToDoList.h"
#include "Task.h"

using namespace std;

int main()
{
    ToDoList *l = new ToDoList;

    l->printUsage();

    do {
        l->takeInput();
    } while (l->getExit() == false);

    delete l;

    return 0;
}
