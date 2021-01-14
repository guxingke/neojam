
#ifndef KKK_SIG_H
#define KKK_SIG_H
#define SCAN_SIG(p, D, S)                   \
   p++;               /* skip start ( */    \
   while(*p != ')') {                       \
       if((*p == 'J') || (*p == 'D')) {     \
          D;                                \
          p++;                              \
      } else {                              \
          S;                                \
          if(*p == '[')                     \
              for(p++; *p == '['; p++);     \
          if(*p == 'L')                     \
              while(*p++ != ';');           \
          else                              \
              p++;                          \
      }                                     \
   }                                        \
   p++;               /* skip end ) */

#endif //KKK_SIG_H
