
#ifndef KKK_LOCK_H
#define KKK_LOCK_H

#include "thread.h"

extern void monitorInit(Monitor *mon);

extern void monitorLock(Monitor *mon, Thread *self);

extern void monitorUnlock(Monitor *mon, Thread *self);

extern int monitorWait(Monitor *mon, Thread *self, long long ms, int ns,
                       int is_wait, int interruptible);

extern int monitorNotify(Monitor *mon, Thread *self);

extern int monitorNotifyAll(Monitor *mon, Thread *self);

extern void objectLock(Object *ob);

extern void objectUnlock(Object *ob);

extern void objectNotify(Object *ob);

extern void objectNotifyAll(Object *ob);

extern void objectWait(Object *ob, long long ms, int ns, int interruptible);

extern int objectLockedByCurrent(Object *ob);

extern Thread *objectLockedBy(Object *ob);

extern void threadMonitorCache();

#endif //KKK_LOCK_H
