
#include <stdio.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "jam.h"
#include "thread.h"
#include "lock.h"
#include "excep.h"
#include "symbol.h"
#include "frame.h"

#include "interp.h"

#include "hash.h"
#include "class.h"
#include "classlib.h"

uintptr_t *executeJava() {
    uintptr_t *arg1;
    register CodePntr pc;
    ExecEnv *ee = getExecEnv();
    Frame *frame = ee->last_frame;
    register uintptr_t *lvars = frame->lvars;
    register uintptr_t *ostack = frame->ostack;

    Object *this = (Object *) lvars[0];
    MethodBlock *new_mb, *mb = frame->mb;
    ConstantPool *cp = &(((ClassBlock *) (mb->class + 1))->constant_pool);


    ;
    pc = (CodePntr) mb->code;


    while (1) {
//        jam_printf("%x %u\n", *pc, *pc);
//        ClassBlock *cb = CLASS_CB(mb->class);
//        if (strcmp(cb->name, "java/io/File") == 0) {
//            jam_printf("%x %u\n", *pc, *pc);
//        }
        switch (*pc) {
            default:
                jam_fprintf(__stdoutp, "Unrecognised opcode %d in: %s.%s\n", *pc,
                            ((ClassBlock *) (mb->class + 1))->name, mb->name);
                exitVM(1);
            case 2: {
                uintptr_t tos = -1;
                *ostack++ = tos;
                {
                    pc += 1;
                    break;
                };
            };
            case 3:
            case 11:
            case 1: {
                uintptr_t tos = 0;
                *ostack++ = tos;
                {
                    pc += 1;
                    break;
                };
            };
            case 4: {
                uintptr_t tos = 1;
                *ostack++ = tos;
                {
                    pc += 1;
                    break;
                };
            };
            case 5: {
                uintptr_t tos = 2;
                *ostack++ = tos;
                {
                    pc += 1;
                    break;
                };
            };
            case 6: {
                uintptr_t tos = 3;
                *ostack++ = tos;
                {
                    pc += 1;
                    break;
                };
            };
            case 7: {
                uintptr_t tos = 4;
                *ostack++ = tos;
                {
                    pc += 1;
                    break;
                };
            };
            case 8: {
                uintptr_t tos = 5;
                *ostack++ = tos;
                {
                    pc += 1;
                    break;
                };
            };
            case 12: {
                uintptr_t tos = 0x3f800000;
                *ostack++ = tos;
                {
                    pc += 1;
                    break;
                };
            };
            case 13: {
                uintptr_t tos = 0x40000000;
                *ostack++ = tos;
                {
                    pc += 1;
                    break;
                };
            };
            case 17: {
                uintptr_t tos = (signed short) (((pc)[1] << 8) | (pc)[2]);
                *ostack++ = tos;
                {
                    pc += 3;
                    break;
                };
            };
            case 16: {
                uintptr_t tos = (signed char) ((pc)[1]);
                *ostack++ = tos;
                {
                    pc += 2;
                    break;
                };
            };
            case 203: {
                uintptr_t tos = cp->info[((pc)[1])];
                *ostack++ = tos;
                {
                    pc += 2;
                    break;
                };
            };
            case 204: {
                uintptr_t tos = cp->info[(((pc)[1] << 8) | (pc)[2])];
                *ostack++ = tos;
                {
                    pc += 3;
                    break;
                };
            };
            case 21:
            case 23:
            case 25: {
                uintptr_t tos = lvars[((pc)[1])];
                *ostack++ = tos;
                {
                    pc += 2;
                    break;
                };
            };
            case 231:
                if (pc[1] != 180) {
                    int opcode;
                    if (pc[1] == 206) opcode = 229; else if (pc[1] == 217) opcode = 221; else opcode = 26;
                    pc[0] = opcode;
                    {
                        pc += 0;
                        break;
                    };
                };
            case 26:
            case 34: {
                uintptr_t tos = lvars[0];
                *ostack++ = tos;
                {
                    pc += 1;
                    break;
                };
            }
            case 27:
            case 35:
            case 43: {
                uintptr_t tos = lvars[1];
                *ostack++ = tos;
                {
                    pc += 1;
                    break;
                };
            };
            case 28:
            case 36:
            case 44: {
                uintptr_t tos = lvars[2];
                *ostack++ = tos;
                {
                    pc += 1;
                    break;
                };
            };
            case 29:
            case 37:
            case 45: {
                uintptr_t tos = lvars[3];
                *ostack++ = tos;
                {
                    pc += 1;
                    break;
                };
            };
            case 54:
            case 56:
            case 58:
                lvars[((pc)[1])] = *--ostack;
                {
                    pc += 2;
                    break;
                };;
            case 59:
            case 75:
            case 67:
                lvars[0] = *--ostack;
                {
                    pc += 1;
                    break;
                };;
            case 60:
            case 76:
            case 68:
                lvars[1] = *--ostack;
                {
                    pc += 1;
                    break;
                };;
            case 61:
            case 77:
            case 69:
                lvars[2] = *--ostack;
                {
                    pc += 1;
                    break;
                };;
            case 62:
            case 78:
            case 70:
                lvars[3] = *--ostack;
                {
                    pc += 1;
                    break;
                };;
            case 96:
                ostack -= 2;
                {
                    uintptr_t tos = (int) ostack[0] + (int) ostack[1];
                    *ostack++ = tos;
                    {
                        pc += 1;
                        break;
                    };
                };;
            case 100:
                ostack -= 2;
                {
                    uintptr_t tos = (int) ostack[0] - (int) ostack[1];
                    *ostack++ = tos;
                    {
                        pc += 1;
                        break;
                    };
                };;
            case 104:
                ostack -= 2;
                {
                    uintptr_t tos = (int) ostack[0] * (int) ostack[1];
                    *ostack++ = tos;
                    {
                        pc += 1;
                        break;
                    };
                };;
            case 108:
                if ((int) ostack[-1] == 0) {
                    frame->last_pc = pc;
                    signalChainedExceptionEnum(exception_java_lang_ArithmeticException, "division by zero",
                                               ((void *) 0));
                    goto throwException;
                };;;
                ostack -= 2;
                {
                    int v1 = ostack[0];
                    int v2 = ostack[1];
                    {
                        uintptr_t tos = v1 / ((v1 == (-2147483647 - 1) && v2 == -1) ? 1 : v2);
                        *ostack++ = tos;
                        {
                            pc += 1;
                            break;
                        };
                    };
                };;
            case 112:
                if ((int) ostack[-1] == 0) {
                    frame->last_pc = pc;
                    signalChainedExceptionEnum(exception_java_lang_ArithmeticException, "division by zero",
                                               ((void *) 0));
                    goto throwException;
                };;;
                ostack -= 2;
                {
                    int v1 = ostack[0];
                    int v2 = ostack[1];
                    {
                        uintptr_t tos = v1 % ((v1 == (-2147483647 - 1) && v2 == -1) ? 1 : v2);
                        *ostack++ = tos;
                        {
                            pc += 1;
                            break;
                        };
                    };
                };;
            case 126:
                ostack -= 2;
                {
                    uintptr_t tos = (int) ostack[0] & (int) ostack[1];
                    *ostack++ = tos;
                    {
                        pc += 1;
                        break;
                    };
                };;
            case 128:
                ostack -= 2;
                {
                    uintptr_t tos = (int) ostack[0] | (int) ostack[1];
                    *ostack++ = tos;
                    {
                        pc += 1;
                        break;
                    };
                };;
            case 130:
                ostack -= 2;
                {
                    uintptr_t tos = (int) ostack[0] ^(int) ostack[1];
                    *ostack++ = tos;
                    {
                        pc += 1;
                        break;
                    };
                };;
            case 116: {
                uintptr_t tos = -({
                    ostack -= (sizeof(int) + 3) / 4;
                    (int) ostack[0];
                });
                *ostack++ = tos;
                {
                    pc += 1;
                    break;
                };
            };;
            case 120:
                ostack -= 2;
                {
                    uintptr_t tos = (int) ostack[0] << (ostack[1] & 0x1f);
                    *ostack++ = tos;
                    {
                        pc += 1;
                        break;
                    };
                };;
            case 122:
                ostack -= 2;
                {
                    uintptr_t tos = (int) ostack[0] >> (ostack[1] & 0x1f);
                    *ostack++ = tos;
                    {
                        pc += 1;
                        break;
                    };
                };;
            case 124:
                ostack -= 2;
                {
                    uintptr_t tos = (unsigned int) ostack[0] >> (ostack[1] & 0x1f);
                    *ostack++ = tos;
                    {
                        pc += 1;
                        break;
                    };
                };;
            case 159:
            case 165:
                ostack -= 2;
                {
                    pc += ((int) ostack[0] == (int) ostack[1]) ? (signed short) (((pc)[1] << 8) | (pc)[2]) : 3;
                    break;
                };;
            case 160:
            case 166:
                ostack -= 2;
                {
                    pc += ((int) ostack[0] != (int) ostack[1]) ? (signed short) (((pc)[1] << 8) | (pc)[2]) : 3;
                    break;
                };;
            case 161:
                ostack -= 2;
                {
                    pc += ((int) ostack[0] < (int) ostack[1]) ? (signed short) (((pc)[1] << 8) | (pc)[2]) : 3;
                    break;
                };;
            case 162:
                ostack -= 2;
                {
                    pc += ((int) ostack[0] >= (int) ostack[1]) ? (signed short) (((pc)[1] << 8) | (pc)[2]) : 3;
                    break;
                };;
            case 163:
                ostack -= 2;
                {
                    pc += ((int) ostack[0] > (int) ostack[1]) ? (signed short) (((pc)[1] << 8) | (pc)[2]) : 3;
                    break;
                };;
            case 164:
                ostack -= 2;
                {
                    pc += ((int) ostack[0] <= (int) ostack[1]) ? (signed short) (((pc)[1] << 8) | (pc)[2]) : 3;
                    break;
                };;
            case 154:
            case 199: {
                pc += ((int) *--ostack != 0) ? (signed short) (((pc)[1] << 8) | (pc)[2]) : 3;
                break;
            };;
            case 153:
            case 198: {
                pc += ((int) *--ostack == 0) ? (signed short) (((pc)[1] << 8) | (pc)[2]) : 3;
                break;
            };;
            case 155: {
                pc += ((int) *--ostack < 0) ? (signed short) (((pc)[1] << 8) | (pc)[2]) : 3;
                break;
            };;
            case 156: {
                pc += ((int) *--ostack >= 0) ? (signed short) (((pc)[1] << 8) | (pc)[2]) : 3;
                break;
            };;
            case 157: {
                pc += ((int) *--ostack > 0) ? (signed short) (((pc)[1] << 8) | (pc)[2]) : 3;
                break;
            };;
            case 158: {
                pc += ((int) *--ostack <= 0) ? (signed short) (((pc)[1] << 8) | (pc)[2]) : 3;
                break;
            };;
            case 132:
                lvars[((pc)[1])] += (signed char) ((pc + 1)[1]);
                {
                    pc += 3;
                    break;
                };
            case 87:
                ostack--;
                {
                    pc += 1;
                    break;
                };;
            case 88:
                ostack -= 2 - 0;
                {
                    pc += 1;
                    break;
                };
            case 89: {
                uintptr_t tos = ostack[-1];
                *ostack++ = tos;
                {
                    pc += 1;
                    break;
                };
            };;
            case 172:
            case 176:
            case 174:
                *lvars++ = *--ostack;
                goto methodReturn;;
            case 177:
                goto methodReturn;
            case 210: {
                uintptr_t tos = *(u4 *) (((FieldBlock *) cp->info[(((pc)[1] << 8) | (pc)[2])])->u.static_value.data);
                *ostack++ = tos;
                {
                    pc += 3;
                    break;
                };
            };
            case 211:
                *(u4 *) (((FieldBlock *) cp->info[(((pc)[1] << 8) | (pc)[2])])->u.static_value.data) = *--ostack;
                {
                    pc += 3;
                    break;
                };;
            case 229: {
                uintptr_t tos = *(u4 *) &((char *) this)[((pc + 1)[1])];
                *ostack++ = tos;
                {
                    pc += 4;
                    break;
                };
            };
            case 206: {
                Object *obj = (Object *) *--ostack;
                if (!obj) {
                    frame->last_pc = pc;
                    signalChainedExceptionEnum(exception_java_lang_NullPointerException, ((void *) 0), ((void *) 0));
                    goto throwException;
                };;
                {
                    uintptr_t tos = *(u4 *) &((char *) obj)[((pc)[1])];
                    *ostack++ = tos;
                    {
                        pc += 3;
                        break;
                    };
                };
            };
            case 219: {
                uintptr_t tos = *(uintptr_t *) (((FieldBlock *) cp->info[(((pc)[1] << 8) |
                                                                          (pc)[2])])->u.static_value.data);
                *ostack++ = tos;
                {
                    pc += 3;
                    break;
                };
            };
            case 220:
                *(uintptr_t *) (((FieldBlock *) cp->info[(((pc)[1] << 8) | (pc)[2])])->u.static_value.data) = *--ostack;
                {
                    pc += 3;
                    break;
                };;
            case 221: {
                uintptr_t tos = *(uintptr_t *) &((char *) this)[((pc + 1)[1])];
                *ostack++ = tos;
                {
                    pc += 4;
                    break;
                };
            };
            case 217: {
                Object *obj = (Object *) *--ostack;
                if (!obj) {
                    frame->last_pc = pc;
                    signalChainedExceptionEnum(exception_java_lang_NullPointerException, ((void *) 0), ((void *) 0));
                    goto throwException;
                };;
                {
                    uintptr_t tos = *(uintptr_t *) &((char *) obj)[((pc)[1])];
                    *ostack++ = tos;
                    {
                        pc += 3;
                        break;
                    };
                };
            };;


            case 0:
                ({
                    {
                        pc += 1;
                        break;
                    };
                });
            case 9:
            case 14:
                ({
                    {
                        uint64_t val = 0;
                        *(uint64_t *) &ostack[0 * 2] = val;
                        ostack += (sizeof(uint64_t) + 3) / 4;
                    };
                    {
                        pc += 1;
                        break;
                    };;
                });


            case 15:
                ({
                    {
                        uint64_t val = 0x3ff0000000000000LL;
                        *(uint64_t *) &ostack[0 * 2] = val;
                        ostack += (sizeof(uint64_t) + 3) / 4;
                    };
                    {
                        pc += 1;
                        break;
                    };;
                });


            case 10:
                ({
                    {
                        uint64_t val = 1;
                        *(uint64_t *) &ostack[0 * 2] = val;
                        ostack += (sizeof(uint64_t) + 3) / 4;
                    };
                    {
                        pc += 1;
                        break;
                    };;
                });


            case 20:
                ({
                    {
                        uint64_t val = *(long long *) &(cp->info[(((pc)[1] << 8) | (pc)[2])]);
                        *(uint64_t *) &ostack[0 * 2] = val;
                        ostack += (sizeof(uint64_t) + 3) / 4;
                    };
                    {
                        pc += 3;
                        break;
                    };;
                });


            case 22:
            case 24:
                ({
                    {
                        uint64_t val = *(u8 *) (&lvars[((pc)[1])]);
                        *(uint64_t *) &ostack[0 * 2] = val;
                        ostack += (sizeof(uint64_t) + 3) / 4;
                    };
                    {
                        pc += 2;
                        break;
                    };;
                });


            case 30:
            case 38:
                ({
                    {
                        uint64_t val = *(u8 *) (&lvars[0]);
                        *(uint64_t *) &ostack[0 * 2] = val;
                        ostack += (sizeof(uint64_t) + 3) / 4;
                    };
                    {
                        pc += 1;
                        break;
                    };;
                });


            case 31:
            case 39:
                ({
                    {
                        uint64_t val = *(u8 *) (&lvars[1]);
                        *(uint64_t *) &ostack[0 * 2] = val;
                        ostack += (sizeof(uint64_t) + 3) / 4;
                    };
                    {
                        pc += 1;
                        break;
                    };;
                });


            case 32:
            case 40:
                ({
                    {
                        uint64_t val = *(u8 *) (&lvars[2]);
                        *(uint64_t *) &ostack[0 * 2] = val;
                        ostack += (sizeof(uint64_t) + 3) / 4;
                    };
                    {
                        pc += 1;
                        break;
                    };;
                });


            case 33:
            case 41:
                ({
                    {
                        uint64_t val = *(u8 *) (&lvars[3]);
                        *(uint64_t *) &ostack[0 * 2] = val;
                        ostack += (sizeof(uint64_t) + 3) / 4;
                    };
                    {
                        pc += 1;
                        break;
                    };;
                });
            case 55:
            case 57:
                *(u8 *) (&lvars[((pc)[1])]) = ({
                    ostack -= (sizeof(uint64_t) + 3) / 4;
                    *(uint64_t *) &ostack[0 * 2];
                });
                {
                    pc += 2;
                    break;
                };;


            case 63:
            case 71:
                *(u8 *) (&lvars[0]) = ({
                    ostack -= (sizeof(uint64_t) + 3) / 4;
                    *(uint64_t *) &ostack[0 * 2];
                });
                {
                    pc += 1;
                    break;
                };;


            case 64:
            case 72:
                *(u8 *) (&lvars[1]) = ({
                    ostack -= (sizeof(uint64_t) + 3) / 4;
                    *(uint64_t *) &ostack[0 * 2];
                });
                {
                    pc += 1;
                    break;
                };;


            case 65:
            case 73:
                *(u8 *) (&lvars[2]) = ({
                    ostack -= (sizeof(uint64_t) + 3) / 4;
                    *(uint64_t *) &ostack[0 * 2];
                });
                {
                    pc += 1;
                    break;
                };;


            case 66:
            case 74:
                *(u8 *) (&lvars[3]) = ({
                    ostack -= (sizeof(uint64_t) + 3) / 4;
                    *(uint64_t *) &ostack[0 * 2];
                });
                {
                    pc += 1;
                    break;
                };;
            case 46:
            case 48: {
                int idx = *--ostack;
                Object *array = (Object *) *--ostack;
                if (!array) {
                    frame->last_pc = pc;
                    signalChainedExceptionEnum(exception_java_lang_NullPointerException, ((void *) 0), ((void *) 0));
                    goto throwException;
                };;
                {
                    if (idx >= *(uintptr_t *) (array + 1)) {
                        char buff[11];
                        __builtin___snprintf_chk(buff, 11, 0, __builtin_object_size(buff, 2 > 1 ? 1 : 0), "%d", idx);
                        {
                            frame->last_pc = pc;
                            signalChainedExceptionEnum(exception_java_lang_ArrayIndexOutOfBoundsException, buff,
                                                       ((void *) 0));
                            goto throwException;
                        };
                    }
                };
                {
                    uintptr_t tos = ((int *) (((uintptr_t *) (array + 1)) + 1))[idx];
                    *ostack++ = tos;
                    {
                        pc += 1;
                        break;
                    };
                };
            }


            case 50: {
                int idx = *--ostack;
                Object *array = (Object *) *--ostack;
                if (!array) {
                    frame->last_pc = pc;
                    signalChainedExceptionEnum(exception_java_lang_NullPointerException, ((void *) 0), ((void *) 0));
                    goto throwException;
                };;
                {
                    if (idx >= *(uintptr_t *) (array + 1)) {
                        char buff[11];
                        __builtin___snprintf_chk(buff, 11, 0, __builtin_object_size(buff, 2 > 1 ? 1 : 0), "%d", idx);
                        {
                            frame->last_pc = pc;
                            signalChainedExceptionEnum(exception_java_lang_ArrayIndexOutOfBoundsException, buff,
                                                       ((void *) 0));
                            goto throwException;
                        };
                    }
                };
                {
                    uintptr_t tos = ((uintptr_t *) (((uintptr_t *) (array + 1)) + 1))[idx];
                    *ostack++ = tos;
                    {
                        pc += 1;
                        break;
                    };
                };
            }


            case 51: {
                int idx = *--ostack;
                Object *array = (Object *) *--ostack;
                if (!array) {
                    frame->last_pc = pc;
                    signalChainedExceptionEnum(exception_java_lang_NullPointerException, ((void *) 0), ((void *) 0));
                    goto throwException;
                };;
                {
                    if (idx >= *(uintptr_t *) (array + 1)) {
                        char buff[11];
                        __builtin___snprintf_chk(buff, 11, 0, __builtin_object_size(buff, 2 > 1 ? 1 : 0), "%d", idx);
                        {
                            frame->last_pc = pc;
                            signalChainedExceptionEnum(exception_java_lang_ArrayIndexOutOfBoundsException, buff,
                                                       ((void *) 0));
                            goto throwException;
                        };
                    }
                };
                {
                    uintptr_t tos = ((signed char *) (((uintptr_t *) (array + 1)) + 1))[idx];
                    *ostack++ = tos;
                    {
                        pc += 1;
                        break;
                    };
                };
            }


            case 52: {
                int idx = *--ostack;
                Object *array = (Object *) *--ostack;
                if (!array) {
                    frame->last_pc = pc;
                    signalChainedExceptionEnum(exception_java_lang_NullPointerException, ((void *) 0), ((void *) 0));
                    goto throwException;
                };;
                {
                    if (idx >= *(uintptr_t *) (array + 1)) {
                        char buff[11];
                        __builtin___snprintf_chk(buff, 11, 0, __builtin_object_size(buff, 2 > 1 ? 1 : 0), "%d", idx);
                        {
                            frame->last_pc = pc;
                            signalChainedExceptionEnum(exception_java_lang_ArrayIndexOutOfBoundsException, buff,
                                                       ((void *) 0));
                            goto throwException;
                        };
                    }
                };
                {
                    uintptr_t tos = ((unsigned short *) (((uintptr_t *) (array + 1)) + 1))[idx];
                    *ostack++ = tos;
                    {
                        pc += 1;
                        break;
                    };
                };
            }


            case 53: {
                int idx = *--ostack;
                Object *array = (Object *) *--ostack;
                if (!array) {
                    frame->last_pc = pc;
                    signalChainedExceptionEnum(exception_java_lang_NullPointerException, ((void *) 0), ((void *) 0));
                    goto throwException;
                };;
                {
                    if (idx >= *(uintptr_t *) (array + 1)) {
                        char buff[11];
                        __builtin___snprintf_chk(buff, 11, 0, __builtin_object_size(buff, 2 > 1 ? 1 : 0), "%d", idx);
                        {
                            frame->last_pc = pc;
                            signalChainedExceptionEnum(exception_java_lang_ArrayIndexOutOfBoundsException, buff,
                                                       ((void *) 0));
                            goto throwException;
                        };
                    }
                };
                {
                    uintptr_t tos = ((short *) (((uintptr_t *) (array + 1)) + 1))[idx];
                    *ostack++ = tos;
                    {
                        pc += 1;
                        break;
                    };
                };
            }


            case 47:
            case 49: {
                int idx = *--ostack;
                Object *array = (Object *) *--ostack;
                if (!array) {
                    frame->last_pc = pc;
                    signalChainedExceptionEnum(exception_java_lang_NullPointerException, ((void *) 0), ((void *) 0));
                    goto throwException;
                };;
                {
                    if (idx >= *(uintptr_t *) (array + 1)) {
                        char buff[11];
                        __builtin___snprintf_chk(buff, 11, 0, __builtin_object_size(buff, 2 > 1 ? 1 : 0), "%d", idx);
                        {
                            frame->last_pc = pc;
                            signalChainedExceptionEnum(exception_java_lang_ArrayIndexOutOfBoundsException, buff,
                                                       ((void *) 0));
                            goto throwException;
                        };
                    }
                };
                {
                    uint64_t val = ((u8 *) (((uintptr_t *) (array + 1)) + 1))[idx];
                    *(uint64_t *) &ostack[0 * 2] = val;
                    ostack += (sizeof(uint64_t) + 3) / 4;
                };
                {
                    pc += 1;
                    break;
                };;
            }
            case 79:
            case 81: {
                int val = *--ostack;
                int idx = *--ostack;
                Object *array = (Object *) *--ostack;
                if (!array) {
                    frame->last_pc = pc;
                    signalChainedExceptionEnum(exception_java_lang_NullPointerException, ((void *) 0), ((void *) 0));
                    goto throwException;
                };;
                {
                    if (idx >= *(uintptr_t *) (array + 1)) {
                        char buff[11];
                        __builtin___snprintf_chk(buff, 11, 0, __builtin_object_size(buff, 2 > 1 ? 1 : 0), "%d", idx);
                        {
                            frame->last_pc = pc;
                            signalChainedExceptionEnum(exception_java_lang_ArrayIndexOutOfBoundsException, buff,
                                                       ((void *) 0));
                            goto throwException;
                        };
                    }
                };
                ((int *) (((uintptr_t *) (array + 1)) + 1))[idx] = val;
                {
                    pc += 1;
                    break;
                };
            }


            case 84: {
                int val = *--ostack;
                int idx = *--ostack;
                Object *array = (Object *) *--ostack;
                if (!array) {
                    frame->last_pc = pc;
                    signalChainedExceptionEnum(exception_java_lang_NullPointerException, ((void *) 0), ((void *) 0));
                    goto throwException;
                };;
                {
                    if (idx >= *(uintptr_t *) (array + 1)) {
                        char buff[11];
                        __builtin___snprintf_chk(buff, 11, 0, __builtin_object_size(buff, 2 > 1 ? 1 : 0), "%d", idx);
                        {
                            frame->last_pc = pc;
                            signalChainedExceptionEnum(exception_java_lang_ArrayIndexOutOfBoundsException, buff,
                                                       ((void *) 0));
                            goto throwException;
                        };
                    }
                };
                ((char *) (((uintptr_t *) (array + 1)) + 1))[idx] = val;
                {
                    pc += 1;
                    break;
                };
            };


            case 85:
            case 86: {
                int val = *--ostack;
                int idx = *--ostack;
                Object *array = (Object *) *--ostack;
                if (!array) {
                    frame->last_pc = pc;
                    signalChainedExceptionEnum(exception_java_lang_NullPointerException, ((void *) 0), ((void *) 0));
                    goto throwException;
                };;
                {
                    if (idx >= *(uintptr_t *) (array + 1)) {
                        char buff[11];
                        __builtin___snprintf_chk(buff, 11, 0, __builtin_object_size(buff, 2 > 1 ? 1 : 0), "%d", idx);
                        {
                            frame->last_pc = pc;
                            signalChainedExceptionEnum(exception_java_lang_ArrayIndexOutOfBoundsException, buff,
                                                       ((void *) 0));
                            goto throwException;
                        };
                    }
                };
                ((short *) (((uintptr_t *) (array + 1)) + 1))[idx] = val;
                {
                    pc += 1;
                    break;
                };
            };


            case 83: {
                Object *obj = (Object *) *--ostack;
                int idx = *--ostack;
                Object *array = (Object *) *--ostack;
                if (!array) {
                    frame->last_pc = pc;
                    signalChainedExceptionEnum(exception_java_lang_NullPointerException, ((void *) 0), ((void *) 0));
                    goto throwException;
                };;
                {
                    if (idx >= *(uintptr_t *) (array + 1)) {
                        char buff[11];
                        __builtin___snprintf_chk(buff, 11, 0, __builtin_object_size(buff, 2 > 1 ? 1 : 0), "%d", idx);
                        {
                            frame->last_pc = pc;
                            signalChainedExceptionEnum(exception_java_lang_ArrayIndexOutOfBoundsException, buff,
                                                       ((void *) 0));
                            goto throwException;
                        };
                    }
                };
                if ((obj != ((void *) 0)) && !arrayStoreCheck(array->class, obj->class)) {
                    frame->last_pc = pc;
                    signalChainedExceptionEnum(exception_java_lang_ArrayStoreException, ((void *) 0), ((void *) 0));
                    goto throwException;
                };
                ((Object **) (((uintptr_t *) (array + 1)) + 1))[idx] = obj;
                {
                    pc += 1;
                    break;
                };
            }
            case 80:
            case 82: {
                int idx = ostack[-3];
                Object *array = (Object *) ostack[-4];
                ostack -= 4;
                if (!array) {
                    frame->last_pc = pc;
                    signalChainedExceptionEnum(exception_java_lang_NullPointerException, ((void *) 0), ((void *) 0));
                    goto throwException;
                };;
                {
                    if (idx >= *(uintptr_t *) (array + 1)) {
                        char buff[11];
                        __builtin___snprintf_chk(buff, 11, 0, __builtin_object_size(buff, 2 > 1 ? 1 : 0), "%d", idx);
                        {
                            frame->last_pc = pc;
                            signalChainedExceptionEnum(exception_java_lang_ArrayIndexOutOfBoundsException, buff,
                                                       ((void *) 0));
                            goto throwException;
                        };
                    }
                };
                ((u8 *) (((uintptr_t *) (array + 1)) + 1))[idx] = *(u8 *) &ostack[2];
                {
                    pc += 1;
                    break;
                };
            }
            case 90: {
                uintptr_t word1 = ostack[-1];
                uintptr_t word2 = ostack[-2];
                ostack[-2] = word1;
                ostack[-1] = word2;
                *ostack++ = word1;
                {
                    pc += 1;
                    break;
                };
            }
            case 91: {
                uintptr_t word1 = ostack[-1];
                uintptr_t word2 = ostack[-2];
                uintptr_t word3 = ostack[-3];
                ostack[-3] = word1;
                ostack[-2] = word3;
                ostack[-1] = word2;
                *ostack++ = word1;
                {
                    pc += 1;
                    break;
                };
            }
            case 92: {
                ostack[0] = ostack[-2];
                ostack[1] = ostack[-1];
                ostack += 2;
                {
                    pc += 1;
                    break;
                };
            }


            case 93: {
                uintptr_t word1 = ostack[-1];
                uintptr_t word2 = ostack[-2];
                uintptr_t word3 = ostack[-3];
                ostack[-3] = word2;
                ostack[-2] = word1;
                ostack[-1] = word3;
                ostack[0] = word2;
                ostack[1] = word1;
                ostack += 2;
                {
                    pc += 1;
                    break;
                };
            }
            case 94: {
                uintptr_t word1 = ostack[-1];
                uintptr_t word2 = ostack[-2];
                uintptr_t word3 = ostack[-3];
                uintptr_t word4 = ostack[-4];
                ostack[-4] = word2;
                ostack[-3] = word1;
                ostack[-2] = word4;
                ostack[-1] = word3;
                ostack[0] = word2;
                ostack[1] = word1;
                ostack += 2;
                {
                    pc += 1;
                    break;
                };
            }
            case 95: {
                uintptr_t word1 = ostack[-1];
                ostack[-1] = ostack[-2];
                ostack[-2] = word1;
                {
                    pc += 1;
                    break;
                }
            }
            case 98:
                ({
                    *((float *) &ostack[-2] + (sizeof(uintptr_t) == 8 && 0)) += *((float *) &ostack[-1] +
                                                                                  (sizeof(uintptr_t) == 8 && 0));
                    ostack -= (sizeof(float) + 3) / 4;
                    {
                        pc += 1;
                        break;
                    };;
                });


            case 99:
                ({
                    *(double *) &ostack[-2 * 2] += *(double *) &ostack[-1 * 2];
                    ostack -= (sizeof(double) + 3) / 4;
                    {
                        pc += 1;
                        break;
                    };;
                });


            case 102:
                ({
                    *((float *) &ostack[-2] + (sizeof(uintptr_t) == 8 && 0)) -= *((float *) &ostack[-1] +
                                                                                  (sizeof(uintptr_t) == 8 && 0));
                    ostack -= (sizeof(float) + 3) / 4;
                    {
                        pc += 1;
                        break;
                    };;
                });


            case 103:
                ({
                    *(double *) &ostack[-2 * 2] -= *(double *) &ostack[-1 * 2];
                    ostack -= (sizeof(double) + 3) / 4;
                    {
                        pc += 1;
                        break;
                    };;
                });


            case 106:
                ({
                    *((float *) &ostack[-2] + (sizeof(uintptr_t) == 8 && 0)) *= *((float *) &ostack[-1] +
                                                                                  (sizeof(uintptr_t) == 8 && 0));
                    ostack -= (sizeof(float) + 3) / 4;
                    {
                        pc += 1;
                        break;
                    };;
                });


            case 107:
                ({
                    *(double *) &ostack[-2 * 2] *= *(double *) &ostack[-1 * 2];
                    ostack -= (sizeof(double) + 3) / 4;
                    {
                        pc += 1;
                        break;
                    };;
                });


            case 110:
                ({
                    *((float *) &ostack[-2] + (sizeof(uintptr_t) == 8 && 0)) /= *((float *) &ostack[-1] +
                                                                                  (sizeof(uintptr_t) == 8 && 0));
                    ostack -= (sizeof(float) + 3) / 4;
                    {
                        pc += 1;
                        break;
                    };;
                });


            case 111:
                ({
                    *(double *) &ostack[-2 * 2] /= *(double *) &ostack[-1 * 2];
                    ostack -= (sizeof(double) + 3) / 4;
                    {
                        pc += 1;
                        break;
                    };;
                });
            case 97:
                *(int64_t *) &ostack[-2 * 2] += *(int64_t *) &ostack[-1 * 2];
                ostack -= (sizeof(int64_t) + 3) / 4;
                {
                    pc += 1;
                    break;
                };;


            case 101:
                *(int64_t *) &ostack[-2 * 2] -= *(int64_t *) &ostack[-1 * 2];
                ostack -= (sizeof(int64_t) + 3) / 4;
                {
                    pc += 1;
                    break;
                };;


            case 105:
                *(int64_t *) &ostack[-2 * 2] *= *(int64_t *) &ostack[-1 * 2];
                ostack -= (sizeof(int64_t) + 3) / 4;
                {
                    pc += 1;
                    break;
                };;


            case 127:
                *(int64_t *) &ostack[-2 * 2] &= *(int64_t *) &ostack[-1 * 2];
                ostack -= (sizeof(int64_t) + 3) / 4;
                {
                    pc += 1;
                    break;
                };;


            case 129:
                *(int64_t *) &ostack[-2 * 2] |= *(int64_t *) &ostack[-1 * 2];
                ostack -= (sizeof(int64_t) + 3) / 4;
                {
                    pc += 1;
                    break;
                };;


            case 131:
                *(int64_t *) &ostack[-2 * 2] ^= *(int64_t *) &ostack[-1 * 2];
                ostack -= (sizeof(int64_t) + 3) / 4;
                {
                    pc += 1;
                    break;
                };;
            case 109:
                if (*(int64_t *) &ostack[-1 * 2] == 0) {
                    frame->last_pc = pc;
                    signalChainedExceptionEnum(exception_java_lang_ArithmeticException, "division by zero",
                                               ((void *) 0));
                    goto throwException;
                };;;
                {
                    int64_t v1 = *(int64_t *) &ostack[-2 * 2];
                    int64_t v2 = *(int64_t *) &ostack[-1 * 2];
                    *(int64_t *) &ostack[-2 * 2] = v1 / ((v1 == (-0x7fffffffffffffffLL - 1) && v2 == -1) ? 1 : v2);
                    ostack -= (sizeof(int64_t) + 3) / 4;
                    {
                        pc += 1;
                        break;
                    };
                };


            case 113:
                if (*(int64_t *) &ostack[-1 * 2] == 0) {
                    frame->last_pc = pc;
                    signalChainedExceptionEnum(exception_java_lang_ArithmeticException, "division by zero",
                                               ((void *) 0));
                    goto throwException;
                };;;
                {
                    int64_t v1 = *(int64_t *) &ostack[-2 * 2];
                    int64_t v2 = *(int64_t *) &ostack[-1 * 2];
                    *(int64_t *) &ostack[-2 * 2] = v1 % ((v1 == (-0x7fffffffffffffffLL - 1) && v2 == -1) ? 1 : v2);
                    ostack -= (sizeof(int64_t) + 3) / 4;
                    {
                        pc += 1;
                        break;
                    };
                };
            case 121: {
                int shift = *--ostack & 0x3f;
                *(int64_t *) &ostack[-1 * 2] <<= shift;
                {
                    pc += 1;
                    break;
                };
            };


            case 123: {
                int shift = *--ostack & 0x3f;
                *(int64_t *) &ostack[-1 * 2] >>= shift;
                {
                    pc += 1;
                    break;
                };
            };


            case 125: {
                int shift = *--ostack & 0x3f;
                *(uint64_t *) &ostack[-1 * 2] >>= shift;
                {
                    pc += 1;
                    break;
                };
            };
            case 114:
                ({
                    *((float *) &ostack[-2] + (sizeof(uintptr_t) == 8 && 0)) = fmod(
                            *((float *) &ostack[-2] + (sizeof(uintptr_t) == 8 && 0)),
                            *((float *) &ostack[-1] + (sizeof(uintptr_t) == 8 && 0)));
                    ostack -= (sizeof(float) + 3) / 4;
                    {
                        pc += 1;
                        break;
                    };;
                });


            case 115:
                ({
                    *(double *) &ostack[-2 * 2] = fmod(*(double *) &ostack[-2 * 2], *(double *) &ostack[-1 * 2]);
                    ostack -= (sizeof(double) + 3) / 4;
                    {
                        pc += 1;
                        break;
                    };;
                });


            case 118:
                ({
                    *((float *) &ostack[-1] + (sizeof(uintptr_t) == 8 && 0)) = -*((float *) &ostack[-1] +
                                                                                  (sizeof(uintptr_t) == 8 && 0));
                    {
                        pc += 1;
                        break;
                    };;
                });


            case 119:
                ({
                    *(double *) &ostack[-1 * 2] = -*(double *) &ostack[-1 * 2];
                    {
                        pc += 1;
                        break;
                    };;
                });


            case 117:
                *(int64_t *) &ostack[-1 * 2] = -*(int64_t *) &ostack[-1 * 2];
                {
                    pc += 1;
                    break;
                };;
            case 136: {
                int64_t value = ({
                    ostack -= (sizeof(int64_t) + 3) / 4;
                    *(int64_t *) &ostack[0 * 2];
                });
                {
                    uintptr_t tos = (int) value;
                    *ostack++ = tos;
                    {
                        pc += 1;
                        break;
                    };
                };
            }
            case 134:
                ({
                    {
                        int value = ({
                            ostack -= (sizeof(int) + 3) / 4;
                            (int) ostack[0];
                        });
                        {
                            float val = (float) value;
                            *((float *) &ostack[0] + (sizeof(uintptr_t) == 8 && 0)) = val;
                            ostack += (sizeof(float) + 3) / 4;
                        };
                        {
                            pc += 1;
                            break;
                        };
                    };
                });


            case 135:
                ({
                    {
                        int value = ({
                            ostack -= (sizeof(int) + 3) / 4;
                            (int) ostack[0];
                        });
                        {
                            double val = (double) value;
                            *(double *) &ostack[0 * 2] = val;
                            ostack += (sizeof(double) + 3) / 4;
                        };
                        {
                            pc += 1;
                            break;
                        };
                    };
                });


            case 137:
                ({
                    {
                        int64_t value = ({
                            ostack -= (sizeof(int64_t) + 3) / 4;
                            *(int64_t *) &ostack[0 * 2];
                        });
                        {
                            float val = (float) value;
                            *((float *) &ostack[0] + (sizeof(uintptr_t) == 8 && 0)) = val;
                            ostack += (sizeof(float) + 3) / 4;
                        };
                        {
                            pc += 1;
                            break;
                        };
                    };
                });


            case 138:
                ({
                    {
                        int64_t value = ({
                            ostack -= (sizeof(int64_t) + 3) / 4;
                            *(int64_t *) &ostack[0 * 2];
                        });
                        {
                            double val = (double) value;
                            *(double *) &ostack[0 * 2] = val;
                            ostack += (sizeof(double) + 3) / 4;
                        };
                        {
                            pc += 1;
                            break;
                        };
                    };
                });


            case 141:
                ({
                    {
                        float value = ({
                            ostack -= (sizeof(float) + 3) / 4;
                            *((float *) &ostack[0] + (sizeof(uintptr_t) == 8 && 0));
                        });
                        {
                            double val = (double) value;
                            *(double *) &ostack[0 * 2] = val;
                            ostack += (sizeof(double) + 3) / 4;
                        };
                        {
                            pc += 1;
                            break;
                        };
                    };
                });


            case 144:
                ({
                    {
                        double value = ({
                            ostack -= (sizeof(double) + 3) / 4;
                            *(double *) &ostack[0 * 2];
                        });
                        {
                            float val = (float) value;
                            *((float *) &ostack[0] + (sizeof(uintptr_t) == 8 && 0)) = val;
                            ostack += (sizeof(float) + 3) / 4;
                        };
                        {
                            pc += 1;
                            break;
                        };
                    };
                });
            case 139:
                ({
                    {
                        int res;
                        float value = ({
                            ostack -= (sizeof(float) + 3) / 4;
                            *((float *) &ostack[0] + (sizeof(uintptr_t) == 8 && 0));
                        });
                        if (value >= (float) 2147483647) res = 2147483647;
                        else if (value <= (float) (-2147483647 - 1))res = (-2147483647 - 1);
                        else if (value != value)res = 0; else res = (int) value;
                        {
                            uintptr_t tos = res;
                            *ostack++ = tos;
                            {
                                pc += 1;
                                break;
                            };
                        };
                    };
                });


            case 142:
                ({
                    {
                        int res;
                        double value = ({
                            ostack -= (sizeof(double) + 3) / 4;
                            *(double *) &ostack[0 * 2];
                        });
                        if (value >= (double) 2147483647) res = 2147483647;
                        else if (value <= (double) (-2147483647 - 1))res = (-2147483647 - 1);
                        else if (value != value)res = 0; else res = (int) value;
                        {
                            uintptr_t tos = res;
                            *ostack++ = tos;
                            {
                                pc += 1;
                                break;
                            };
                        };
                    };
                });
            case 140:
                ({
                    {
                        int64_t res;
                        float value = ({
                            ostack -= (sizeof(float) + 3) / 4;
                            *((float *) &ostack[0] + (sizeof(uintptr_t) == 8 && 0));
                        });
                        if (value >= (float) 0x7fffffffffffffffLL) res = 0x7fffffffffffffffLL;
                        else if (value <= (float) (-0x7fffffffffffffffLL - 1))
                            res = (-0x7fffffffffffffffLL - 1);
                        else if (value != value) res = 0; else res = (int64_t) value;
                        {
                            uint64_t val = res;
                            *(uint64_t *) &ostack[0 * 2] = val;
                            ostack += (sizeof(uint64_t) + 3) / 4;
                        };
                        {
                            pc += 1;
                            break;
                        };;
                    };
                });


            case 143:
                ({
                    {
                        int64_t res;
                        double value = ({
                            ostack -= (sizeof(double) + 3) / 4;
                            *(double *) &ostack[0 * 2];
                        });
                        if (value >= (double) 0x7fffffffffffffffLL) res = 0x7fffffffffffffffLL;
                        else if (value <= (double) (-0x7fffffffffffffffLL - 1))
                            res = (-0x7fffffffffffffffLL - 1);
                        else if (value != value) res = 0; else res = (int64_t) value;
                        {
                            uint64_t val = res;
                            *(uint64_t *) &ostack[0 * 2] = val;
                            ostack += (sizeof(uint64_t) + 3) / 4;
                        };
                        {
                            pc += 1;
                            break;
                        };;
                    };
                });


            case 133:
                ({
                    {
                        uint64_t val = ({
                            ostack -= (sizeof(int) + 3) / 4;
                            (int) ostack[0];
                        });
                        *(uint64_t *) &ostack[0 * 2] = val;
                        ostack += (sizeof(uint64_t) + 3) / 4;
                    };
                    {
                        pc += 1;
                        break;
                    };;
                });


            case 145:
                ({
                    {
                        uintptr_t tos = ({
                            ostack -= (sizeof(int8_t) + 3) / 4;
                            (int8_t) ostack[0];
                        });
                        *ostack++ = tos;
                        {
                            pc += 1;
                            break;
                        };
                    };
                });


            case 146:
                ({
                    {
                        uintptr_t tos = ({
                            ostack -= (sizeof(uint16_t) + 3) / 4;
                            (uint16_t) ostack[0];
                        });
                        *ostack++ = tos;
                        {
                            pc += 1;
                            break;
                        };
                    };
                });


            case 147:
                ({
                    {
                        uintptr_t tos = ({
                            ostack -= (sizeof(int16_t) + 3) / 4;
                            (int16_t) ostack[0];
                        });
                        *ostack++ = tos;
                        {
                            pc += 1;
                            break;
                        };
                    };
                });


            case 148: {
                int64_t v2 = ({
                    ostack -= (sizeof(int64_t) + 3) / 4;
                    *(int64_t *) &ostack[0 * 2];
                });
                int64_t v1 = ({
                    ostack -= (sizeof(int64_t) + 3) / 4;
                    *(int64_t *) &ostack[0 * 2];
                });
                {
                    uintptr_t tos = v1 == v2 ? 0 : (v1 < v2 ? -1 : 1);
                    *ostack++ = tos;
                    {
                        pc += 1;
                        break;
                    };
                };
            }
            case 152:
                ({
                    ({
                        int res;
                        double v2 = ({
                            ostack -= (sizeof(double) + 3) / 4;
                            *(double *) &ostack[0 * 2];
                        });
                        double v1 = ({
                            ostack -= (sizeof(double) + 3) / 4;
                            *(double *) &ostack[0 * 2];
                        });
                        if (v1 == v2) res = 0; else if (v1 < v2) res = -1; else if (v1 > v2) res = 1; else res = 1;
                        {
                            uintptr_t tos = res;
                            *ostack++ = tos;
                            {
                                pc += 1;
                                break;
                            };
                        };
                    });
                });


            case 151:
                ({
                    ({
                        int res;
                        double v2 = ({
                            ostack -= (sizeof(double) + 3) / 4;
                            *(double *) &ostack[0 * 2];
                        });
                        double v1 = ({
                            ostack -= (sizeof(double) + 3) / 4;
                            *(double *) &ostack[0 * 2];
                        });
                        if (v1 == v2) res = 0; else if (v1 < v2) res = -1; else if (v1 > v2) res = 1; else res = -1;
                        {
                            uintptr_t tos = res;
                            *ostack++ = tos;
                            {
                                pc += 1;
                                break;
                            };
                        };
                    });
                });


            case 150:
                ({
                    ({
                        int res;
                        float v2 = ({
                            ostack -= (sizeof(float) + 3) / 4;
                            *((float *) &ostack[0] + (sizeof(uintptr_t) == 8 && 0));
                        });
                        float v1 = ({
                            ostack -= (sizeof(float) + 3) / 4;
                            *((float *) &ostack[0] + (sizeof(uintptr_t) == 8 && 0));
                        });
                        if (v1 == v2) res = 0; else if (v1 < v2) res = -1; else if (v1 > v2) res = 1; else res = 1;
                        {
                            uintptr_t tos = res;
                            *ostack++ = tos;
                            {
                                pc += 1;
                                break;
                            };
                        };
                    });
                });


            case 149:
                ({
                    ({
                        int res;
                        float v2 = ({
                            ostack -= (sizeof(float) + 3) / 4;
                            *((float *) &ostack[0] + (sizeof(uintptr_t) == 8 && 0));
                        });
                        float v1 = ({
                            ostack -= (sizeof(float) + 3) / 4;
                            *((float *) &ostack[0] + (sizeof(uintptr_t) == 8 && 0));
                        });
                        if (v1 == v2) res = 0; else if (v1 < v2) res = -1; else if (v1 > v2) res = 1; else res = -1;
                        {
                            uintptr_t tos = res;
                            *ostack++ = tos;
                            {
                                pc += 1;
                                break;
                            };
                        };
                    });
                });


            case 167:
                ({
                    ({
                        {
                            pc += (1) ? (signed short) (((pc)[1] << 8) | (pc)[2]) : 3;
                            break;
                        };
                    });
                });

            case 168:
                ({
                    ({
                        *ostack++ = (uintptr_t) pc;
                        {
                            pc += (1) ? (signed short) (((pc)[1] << 8) | (pc)[2]) : 3;
                            break;
                        };
                    });
                });


            case 169:
                ({
                    pc = (CodePntr) lvars[((pc)[1])];
                    {
                        pc += 3;
                        break;
                    };
                });


            case 173:
            case 175:
                *(u8 *) lvars = ({
                    ostack -= (sizeof(uint64_t) + 3) / 4;
                    *(uint64_t *) &ostack[0 * 2];
                });
                lvars += 2;
                goto methodReturn;
            case 190:
                ({
                    {
                        Object *array = (Object *) *--ostack;
                        if (!array) {
                            frame->last_pc = pc;
                            signalChainedExceptionEnum(exception_java_lang_NullPointerException, ((void *) 0),
                                                       ((void *) 0));
                            goto throwException;
                        };;
                        {
                            uintptr_t tos = *(uintptr_t *) (array + 1);
                            *ostack++ = tos;
                            {
                                pc += 1;
                                break;
                            };
                        };
                    }
                });


            case 191:
                ({
                    {
                        Object *obj = (Object *) ostack[-1];
                        frame->last_pc = pc;
                        if (!obj) {
                            frame->last_pc = pc;
                            signalChainedExceptionEnum(exception_java_lang_NullPointerException, ((void *) 0),
                                                       ((void *) 0));
                            goto throwException;
                        };;
                        ee->exception = obj;
                        goto throwException;
                    }
                });
            case 188:
                ({
                    {
                        int type = ((pc)[1]);
                        int count = *--ostack;
                        Object *obj;
                        frame->last_pc = pc;
                        if ((obj = allocTypeArray(type, count)) == ((void *) 0)) goto throwException;
                        {
                            uintptr_t tos = (uintptr_t) obj;
                            *ostack++ = tos;
                            {
                                pc += 2;
                                break;
                            };
                        };
                    }
                });
            case 194:
                ({
                    {
                        Object *obj = (Object *) *--ostack;
                        if (!obj) {
                            frame->last_pc = pc;
                            signalChainedExceptionEnum(exception_java_lang_NullPointerException, ((void *) 0),
                                                       ((void *) 0));
                            goto throwException;
                        };;
                        objectLock(obj);
                        {
                            pc += 1;
                            break;
                        };
                    }
                });


            case 195:
                ({
                    {
                        Object *obj = (Object *) *--ostack;
                        if (!obj) {
                            frame->last_pc = pc;
                            signalChainedExceptionEnum(exception_java_lang_NullPointerException, ((void *) 0),
                                                       ((void *) 0));
                            goto throwException;
                        };;
                        objectUnlock(obj);
                        {
                            pc += 1;
                            break;
                        };
                    }
                });
            case 18:
                ({
                    {
                        frame->last_pc = pc;
                        resolveSingleConstant(mb->class, ((pc)[1]));
                        if (ee->exception) goto throwException;
                        pc[0] = 203;
                        {
                            pc += 0;
                            break;
                        };
                    }
                });
            case 19:
                ({
                    {
                        frame->last_pc = pc;
                        resolveSingleConstant(mb->class, (((pc)[1] << 8) | (pc)[2]));
                        if (ee->exception) goto throwException;
                        pc[0] = 204;
                        {
                            pc += 0;
                            break;
                        };
                    }
                });
            case 42:
                ({
                    {
                        if (mb->access_flags & 0x0008) pc[0] = 26; else pc[0] = 231;
                        {
                            pc += 0;
                            break;
                        };
                    }
                });


            case 170:
                ({
                    {
                        int *aligned_pc = (int *) ((uintptr_t) (pc + 4) & ~0x3);
                        int deflt = (__builtin_constant_p(aligned_pc[0]) ? ((__uint32_t) (
                                (((__uint32_t) (aligned_pc[0]) & 0xff000000) >> 24) |
                                (((__uint32_t) (aligned_pc[0]) & 0x00ff0000) >> 8) |
                                (((__uint32_t) (aligned_pc[0]) & 0x0000ff00) << 8) |
                                (((__uint32_t) (aligned_pc[0]) & 0x000000ff) << 24))) : _OSSwapInt32(aligned_pc[0]));
                        int low = (__builtin_constant_p(aligned_pc[1]) ? ((__uint32_t) (
                                (((__uint32_t) (aligned_pc[1]) & 0xff000000) >> 24) |
                                (((__uint32_t) (aligned_pc[1]) & 0x00ff0000) >> 8) |
                                (((__uint32_t) (aligned_pc[1]) & 0x0000ff00) << 8) |
                                (((__uint32_t) (aligned_pc[1]) & 0x000000ff) << 24))) : _OSSwapInt32(aligned_pc[1]));
                        int high = (__builtin_constant_p(aligned_pc[2]) ? ((__uint32_t) (
                                (((__uint32_t) (aligned_pc[2]) & 0xff000000) >> 24) |
                                (((__uint32_t) (aligned_pc[2]) & 0x00ff0000) >> 8) |
                                (((__uint32_t) (aligned_pc[2]) & 0x0000ff00) << 8) |
                                (((__uint32_t) (aligned_pc[2]) & 0x000000ff) << 24))) : _OSSwapInt32(aligned_pc[2]));
                        int index = *--ostack;
                        {
                            pc += (index < low || index > high) ? deflt : (__builtin_constant_p(
                                    aligned_pc[index - low + 3]) ? ((__uint32_t) (
                                    (((__uint32_t) (aligned_pc[index - low + 3]) & 0xff000000) >> 24) |
                                    (((__uint32_t) (aligned_pc[index - low + 3]) & 0x00ff0000) >> 8) |
                                    (((__uint32_t) (aligned_pc[index - low + 3]) & 0x0000ff00) << 8) |
                                    (((__uint32_t) (aligned_pc[index - low + 3]) & 0x000000ff) << 24))) : _OSSwapInt32(
                                    aligned_pc[index - low + 3]));
                            break;
                        };
                    }
                });
            case 171:
                ({
                    {
                        int *aligned_pc = (int *) ((uintptr_t) (pc + 4) & ~0x3);
                        int deflt = (__builtin_constant_p(aligned_pc[0]) ? ((__uint32_t) (
                                (((__uint32_t) (aligned_pc[0]) & 0xff000000) >> 24) |
                                (((__uint32_t) (aligned_pc[0]) & 0x00ff0000) >> 8) |
                                (((__uint32_t) (aligned_pc[0]) & 0x0000ff00) << 8) |
                                (((__uint32_t) (aligned_pc[0]) & 0x000000ff) << 24))) : _OSSwapInt32(aligned_pc[0]));
                        int npairs = (__builtin_constant_p(aligned_pc[1]) ? ((__uint32_t) (
                                (((__uint32_t) (aligned_pc[1]) & 0xff000000) >> 24) |
                                (((__uint32_t) (aligned_pc[1]) & 0x00ff0000) >> 8) |
                                (((__uint32_t) (aligned_pc[1]) & 0x0000ff00) << 8) |
                                (((__uint32_t) (aligned_pc[1]) & 0x000000ff) << 24))) : _OSSwapInt32(aligned_pc[1]));
                        int key = *--ostack;
                        int i;
                        for (i = 2; (i < npairs * 2 + 2) && (key !=
                                                             (__builtin_constant_p(aligned_pc[i]) ? ((__uint32_t) (
                                                                     (((__uint32_t) (aligned_pc[i]) & 0xff000000)
                                                                             >> 24) |
                                                                     (((__uint32_t) (aligned_pc[i]) & 0x00ff0000)
                                                                             >> 8) |
                                                                     (((__uint32_t) (aligned_pc[i]) & 0x0000ff00)
                                                                             << 8) |
                                                                     (((__uint32_t) (aligned_pc[i]) & 0x000000ff)
                                                                             << 24))) : _OSSwapInt32(
                                                                     aligned_pc[i]))); i += 2);
                        {
                            pc += i == npairs * 2 + 2 ? deflt : (__builtin_constant_p(aligned_pc[i + 1])
                                                                 ? ((__uint32_t) (
                                            (((__uint32_t) (aligned_pc[i + 1]) & 0xff000000) >> 24) |
                                            (((__uint32_t) (aligned_pc[i + 1]) & 0x00ff0000) >> 8) |
                                            (((__uint32_t) (aligned_pc[i + 1]) & 0x0000ff00) << 8) |
                                            (((__uint32_t) (aligned_pc[i + 1]) & 0x000000ff) << 24))) : _OSSwapInt32(
                                            aligned_pc[i + 1]));
                            break;
                        };
                    }
                });
            case 178:
                ({
                    {
                        FieldBlock *fb;
                        int opcode;
                        frame->last_pc = pc;
                        fb = resolveField(mb->class, (((pc)[1] << 8) | (pc)[2]));
                        if (fb != ((void *) 0)) initClass(fb->class);
                        if (ee->exception) goto throwException;
                        if ((*fb->type == 'J') || (*fb->type == 'D')) opcode = 212;
                        else if (*fb->type == 'L' || *fb->type == '[')opcode = 219; else opcode = 210;
                        pc[0] = opcode;
                        {
                            pc += 0;
                            break;
                        };
                    }
                });
            case 179:
                ({
                    {
                        FieldBlock *fb;
                        int opcode;
                        frame->last_pc = pc;
                        fb = resolveField(mb->class, (((pc)[1] << 8) | (pc)[2]));
                        if (fb != ((void *) 0)) initClass(fb->class);
                        if (ee->exception) goto throwException;
                        if ((*fb->type == 'J') || (*fb->type == 'D')) opcode = 213;
                        else if (*fb->type == 'L' || *fb->type == '[')opcode = 220; else opcode = 211;
                        pc[0] = opcode;
                        {
                            pc += 0;
                            break;
                        };
                    }
                });
            case 180:
                ({
                    ({
                        int idx;
                        FieldBlock *fb;
                        idx = (((pc)[1] << 8) | (pc)[2]); __asm__ __volatile__ ("mfence":: : "memory"); if ((pc[0] !=
                                                                                                             180)) {
                            pc += 0;
                            break;
                        };;
                        frame->last_pc = pc;
                        fb = resolveField(mb->class, idx);
                        if (ee->exception) goto throwException;
                        if (fb->u.offset > 255) pc[0] = 227;
                        else {
                            int opcode;
                            if ((*fb->type == 'J') || (*fb->type == 'D')) opcode = 208;
                            else if (*fb->type == 'L' || *fb->type == '[')opcode = 217; else opcode = 206;
                            { pc[0] = 230; __asm__ __volatile__ ("mfence":: : "memory"); pc[1] = fb->u.offset; __asm__ __volatile__ ("mfence":: : "memory"); pc[0] = opcode; };
                        }
                        {
                            pc += 0;
                            break;
                        };
                    });
                });
            case 181:
                ({
                    {
                        int idx;
                        FieldBlock *fb;
                        idx = (((pc)[1] << 8) | (pc)[2]); __asm__ __volatile__ ("mfence":: : "memory"); if ((pc[0] !=
                                                                                                             181)) {
                            pc += 0;
                            break;
                        };;
                        frame->last_pc = pc;
                        fb = resolveField(mb->class, idx);
                        if (ee->exception) goto throwException;
                        if (fb->u.offset > 255) pc[0] = 228;
                        else {
                            int opcode;
                            if ((*fb->type == 'J') || (*fb->type == 'D')) opcode = 209;
                            else if (*fb->type == 'L' || *fb->type == '[')opcode = 218; else opcode = 207;
                            { pc[0] = 230; __asm__ __volatile__ ("mfence":: : "memory"); pc[1] = fb->u.offset; __asm__ __volatile__ ("mfence":: : "memory"); pc[0] = opcode; };
                        }
                        {
                            pc += 0;
                            break;
                        };
                    }
                });
            case 227:
                ({
                    {
                        FieldBlock *fb = ((FieldBlock *) cp->info[(((pc)[1] << 8) | (pc)[2])]);
                        Object *obj = (Object *) *--ostack;
                        if (!obj) {
                            frame->last_pc = pc;
                            signalChainedExceptionEnum(exception_java_lang_NullPointerException, ((void *) 0),
                                                       ((void *) 0));
                            goto throwException;
                        };;
                        if ((*fb->type == 'J') || (*fb->type == 'D')) {
                            {
                                uint64_t val = *(u8 *) &((char *) obj)[fb->u.offset];
                                *(uint64_t *) &ostack[0 * 2] = val;
                                ostack += (sizeof(uint64_t) + 3) / 4;
                            };
                            {
                                pc += 3;
                                break;
                            };;
                        } else {
                            if (*fb->type == 'L' || *fb->type == '[') {
                                {
                                    uintptr_t tos = *(uintptr_t *) &((char *) obj)[fb->u.offset];
                                    *ostack++ = tos;
                                    {
                                        pc += 3;
                                        break;
                                    };
                                };
                            } else {
                                {
                                    uintptr_t tos = *(u4 *) &((char *) obj)[fb->u.offset];
                                    *ostack++ = tos;
                                    {
                                        pc += 3;
                                        break;
                                    };
                                };
                            }
                        }
                    }
                });
            case 228: {
                FieldBlock *fb = ((FieldBlock *) cp->info[(((pc)[1] << 8) | (pc)[2])]);
                if ((*fb->type == 'J') || (*fb->type == 'D')) {
                    Object *obj = (Object *) ostack[-3];
                    ostack -= 3;
                    if (!obj) {
                        frame->last_pc = pc;
                        signalChainedExceptionEnum(exception_java_lang_NullPointerException, ((void *) 0),
                                                   ((void *) 0));
                        goto throwException;
                    };;
                    *(u8 *) &((char *) obj)[fb->u.offset] = *(u8 *) &ostack[1];
                } else {
                    Object *obj = (Object *) ostack[-2];
                    ostack -= 2;
                    if (!obj) {
                        frame->last_pc = pc;
                        signalChainedExceptionEnum(exception_java_lang_NullPointerException, ((void *) 0),
                                                   ((void *) 0));
                        goto throwException;
                    };;
                    if (*fb->type == 'L' || *fb->type == '[')
                        *(uintptr_t *) &((char *) obj)[fb->u.offset] = ostack[1];
                    else *(u4 *) &((char *) obj)[fb->u.offset] = ostack[1];
                }
                {
                    pc += 3;
                    break;
                };
            }
            case 182:
                ({
                    {
                        int idx;
                        idx = (((pc)[1] << 8) | (pc)[2]); __asm__ __volatile__ ("mfence":: : "memory"); if ((pc[0] !=
                                                                                                             182)) {
                            pc += 0;
                            break;
                        };;
                        frame->last_pc = pc;
                        new_mb = resolveMethod(mb->class, idx);
                        if (new_mb == ((void *) 0) || ee->exception) {
                            if (0) {
                                PolyMethodBlock *pmb;
                                clearException();
                                pmb = ({ ((void *) 0); });
                                if (pmb == ((void *) 0)) goto throwException;
                                pc[0] = 244;
                            } else goto throwException;
                        } else if (new_mb->access_flags & 0x0002) {
                            if (0 == 1) { pc[0] = 245; }
                            else pc[0] = 215;
                        } else if ((new_mb->args_count < 256) && (new_mb->method_table_index < 256)) {
                            {
                                pc[0] = 230; __asm__ __volatile__ ("mfence":: : "memory"); pc[1] = new_mb->method_table_index;
                                pc[2] = new_mb->args_count; __asm__ __volatile__ ("mfence":: : "memory"); pc[0] = 214;
                            };
                        } else pc[0] = 226;
                        {
                            pc += 0;
                            break;
                        };
                    }
                });
            case 226:
                ({
                    {
                        Class *new_class;
                        new_mb = ((MethodBlock *) cp->info[(((pc)[1] << 8) | (pc)[2])]);
                        arg1 = ostack - new_mb->args_count;
                        if (!*arg1) {
                            frame->last_pc = pc;
                            signalChainedExceptionEnum(exception_java_lang_NullPointerException, ((void *) 0),
                                                       ((void *) 0));
                            goto throwException;
                        };;
                        new_class = (*(Object **) arg1)->class;
                        new_mb = ((ClassBlock *) (new_class + 1))->method_table[new_mb->method_table_index];
                        goto invokeMethod;
                    }
                });
            case 183:
                ({
                    {
                        int idx;
                        idx = (((pc)[1] << 8) | (pc)[2]); __asm__ __volatile__ ("mfence":: : "memory"); if ((pc[0] !=
                                                                                                             183)) {
                            pc += 0;
                            break;
                        };;
                        frame->last_pc = pc;
                        new_mb = resolveMethod(mb->class, idx);
                        if (ee->exception) goto throwException;
                        if ((((ClassBlock *) (mb->class + 1))->access_flags & 0x0020) &&
                            isSubClassOf(new_mb->class, ((ClassBlock *) (mb->class + 1))->super) && (new_mb->name[0] !=
                                                                                                     '<')) {
                            {
                                pc[0] = 230; __asm__ __volatile__ ("mfence":: : "memory"); pc[1] = new_mb->method_table_index
                                        >> 8;
                                pc[2] = new_mb->method_table_index &
                                        0xff; __asm__ __volatile__ ("mfence":: : "memory"); pc[0] = 216;
                            };
                        } else pc[0] = 215;
                        {
                            pc += 0;
                            break;
                        };
                    }
                });
            case OPC_INVOKESTATIC:
                ({
                    {
                        int id;
                        frame->last_pc = pc;
                        new_mb = resolveMethod(mb->class, (((pc)[1] << 8) | (pc)[2]));
                        if (new_mb != ((void *) 0)) initClass(new_mb->class);
                        if (ee->exception) goto throwException;
                        if ((id = 0) >= 1) {
                            int opcode;
                            if (id < 1) opcode = 246; else opcode = 247 + id - 1;
                            pc[0] = opcode;
                        } else pc[0] = 232;
                        {
                            pc += 0;
                            break;
                        };
                    }
                });
            case 185:
                ({
                    {
                        frame->last_pc = pc;
                        new_mb = resolveInterfaceMethod(mb->class, (((pc)[1] << 8) | (pc)[2]));
                        if (ee->exception) goto throwException;
                        if (((ClassBlock *) (new_mb->class + 1))->access_flags & 0x0200)
                            pc[0] = 249;
                        else {
                            pc[3] = pc[4] = 0;
                            pc[0] = 182;
                        }
                        {
                            pc += 0;
                            break;
                        };
                    }
                });
            case 189:
                ({
                    {
                        frame->last_pc = pc;
                        resolveClass(mb->class, (((pc)[1] << 8) | (pc)[2]), 1, 0);
                        if (ee->exception) goto throwException;
                        pc[0] = (189 + 235 - 189);
                        {
                            pc += 0;
                            break;
                        };
                    }
                });
            case 192:
                ({
                    {
                        frame->last_pc = pc;
                        resolveClass(mb->class, (((pc)[1] << 8) | (pc)[2]), 1, 0);
                        if (ee->exception) goto throwException;
                        pc[0] = (192 + 235 - 189);
                        {
                            pc += 0;
                            break;
                        };
                    }
                });
            case 193:
                ({
                    {
                        frame->last_pc = pc;
                        resolveClass(mb->class, (((pc)[1] << 8) | (pc)[2]), 1, 0);
                        if (ee->exception) goto throwException;
                        pc[0] = (193 + 235 - 189);
                        {
                            pc += 0;
                            break;
                        };
                    }
                });
            case 197:
                ({
                    {
                        frame->last_pc = pc;
                        resolveClass(mb->class, (((pc)[1] << 8) | (pc)[2]), 1, 0);
                        if (ee->exception) goto throwException;
                        pc[0] = (197 + 235 - 189);
                        {
                            pc += 0;
                            break;
                        };
                    }
                });

            case 187:
                ({
                    {
                        Class *class;
                        ClassBlock *cb;
                        frame->last_pc = pc;
                        class = resolveClass(mb->class, (((pc)[1] << 8) | (pc)[2]), 1, 1);
                        if (ee->exception) goto throwException;
                        cb = ((ClassBlock *) (class + 1));
                        if (cb->access_flags & (0x0200 | 0x0400)) {
                            signalChainedExceptionEnum(exception_java_lang_InstantiationError, cb->name, ((void *) 0));
                            goto throwException;
                        }
                        pc[0] = 233;
                        {
                            pc += 0;
                            break;
                        };
                    }
                });
            case 196:
                ({
                    {
                        int opcode = pc[1];
                        switch (opcode) {
                            case 21:
                            case 23:
                            case 25:
                                *ostack++ = lvars[(((pc + 1)[1] << 8) | (pc + 1)[2])];
                                pc += 4;
                                break;
                            case 22:
                            case 24:
                                *(u8 *) ostack = *(u8 *) (&lvars[(((pc + 1)[1] << 8) | (pc + 1)[2])]);
                                ostack += 2;
                                pc += 4;
                                break;
                            case 54:
                            case 56:
                            case 58:
                                lvars[(((pc + 1)[1] << 8) | (pc + 1)[2])] = *--ostack;
                                pc += 4;
                                break;
                            case 55:
                            case 57:
                                ostack -= 2;
                                *(u8 *) (&lvars[(((pc + 1)[1] << 8) | (pc + 1)[2])]) = *(u8 *) ostack;
                                pc += 4;
                                break;
                            case 169:
                                pc = (unsigned char *) lvars[((((pc + 1))[1] << 8) | ((pc + 1))[2])];
                                break;
                            case 132:
                                lvars[(((pc + 1)[1] << 8) | (pc + 1)[2])] += (signed short) (((pc + 3)[1] << 8) |
                                                                                             (pc + 3)[2]);
                                pc += 6;
                                break;
                        }
                        {
                            pc += 0;
                            break;
                        };
                    }
                });
            case 200:
                ({
                    {
                        {
                            pc += (signed int) (((pc)[1] << 24) | ((pc)[2] << 16) | ((pc)[3] << 8) | (pc)[4]);
                            break;
                        };
                    }
                });


            case 201:
                ({
                    {
                        {
                            uintptr_t tos = (uintptr_t) pc + 2;
                            *ostack++ = tos;
                            {
                                pc += (signed int) (((pc)[1] << 24) | ((pc)[2] << 16) | ((pc)[3] << 8) | (pc)[4]);
                                break;
                            };
                        };
                    }
                });


            case 230:
                ({
                    {
                        {
                            pc += 0;
                            break;
                        };
                    }
                });


            case 212:
                ({
                    {
                        FieldBlock *fb = ((FieldBlock *) cp->info[(((pc)[1] << 8) | (pc)[2])]);
                        {
                            uint64_t val = fb->u.static_value.l;
                            *(uint64_t *) &ostack[0 * 2] = val;
                            ostack += (sizeof(uint64_t) + 3) / 4;
                        };
                        {
                            pc += 3;
                            break;
                        };;
                    }
                });


            case 213: {
                FieldBlock *fb = ((FieldBlock *) cp->info[(((pc)[1] << 8) | (pc)[2])]);
                fb->u.static_value.l = ({
                    ostack -= (sizeof(uint64_t) + 3) / 4;
                    *(uint64_t *) &ostack[0 * 2];
                });
                {
                    pc += 3;
                    break;
                };;
            }


            case 208:
                ({
                    {
                        Object *obj = (Object *) *--ostack;
                        if (!obj) {
                            frame->last_pc = pc;
                            signalChainedExceptionEnum(exception_java_lang_NullPointerException, ((void *) 0),
                                                       ((void *) 0));
                            goto throwException;
                        };;
                        {
                            uint64_t val = *(u8 *) &((char *) obj)[((pc)[1])];
                            *(uint64_t *) &ostack[0 * 2] = val;
                            ostack += (sizeof(uint64_t) + 3) / 4;
                        };
                        {
                            pc += 3;
                            break;
                        };;
                    }
                });
            case 209: {
                Object *obj = (Object *) ostack[-3];
                ostack -= 3;
                if (!obj) {
                    frame->last_pc = pc;
                    signalChainedExceptionEnum(exception_java_lang_NullPointerException, ((void *) 0), ((void *) 0));
                    goto throwException;
                };;
                *(u8 *) &((char *) obj)[((pc)[1])] = *(u8 *) &ostack[1];
                {
                    pc += 3;
                    break;
                };
            }
            case 207: {
                Object *obj = (Object *) ostack[-2];
                ostack -= 2;
                if (!obj) {
                    frame->last_pc = pc;
                    signalChainedExceptionEnum(exception_java_lang_NullPointerException, ((void *) 0), ((void *) 0));
                    goto throwException;
                };;
                *(u4 *) &((char *) obj)[((pc)[1])] = ostack[1];
                {
                    pc += 3;
                    break;
                };
            }
            case 218: {
                Object *obj = (Object *) ostack[-2];
                ostack -= 2;
                if (!obj) {
                    frame->last_pc = pc;
                    signalChainedExceptionEnum(exception_java_lang_NullPointerException, ((void *) 0), ((void *) 0));
                    goto throwException;
                };;
                *(uintptr_t *) &((char *) obj)[((pc)[1])] = ostack[1];
                {
                    pc += 3;
                    break;
                };
            }

            case 216:
                ({
                    {
                        new_mb = ((ClassBlock *) (((ClassBlock *) (mb->class + 1))->super + 1))->method_table[(
                                ((pc)[1] << 8) | (pc)[2])];
                        arg1 = ostack - new_mb->args_count;
                        if (!*arg1) {
                            frame->last_pc = pc;
                            signalChainedExceptionEnum(exception_java_lang_NullPointerException, ((void *) 0),
                                                       ((void *) 0));
                            goto throwException;
                        };;
                        goto invokeMethod;
                    }
                });


            case 215:
                ({
                    {
                        new_mb = ((MethodBlock *) cp->info[(((pc)[1] << 8) | (pc)[2])]);
                        arg1 = ostack - new_mb->args_count;
                        if (!*arg1) {
                            frame->last_pc = pc;
                            signalChainedExceptionEnum(exception_java_lang_NullPointerException, ((void *) 0),
                                                       ((void *) 0));
                            goto throwException;
                        };;
                        goto invokeMethod;
                    }
                });


            case 232:
                ({
                    {
                        new_mb = ((MethodBlock *) cp->info[(((pc)[1] << 8) | (pc)[2])]);
                        arg1 = ostack - new_mb->args_count;
                        goto invokeMethod;
                    }
                });


            case 249:
                ({
                    {
                        int mtbl_idx;
                        ClassBlock *cb;
                        int cache = ((pc + 3)[1]);
                        new_mb = (MethodBlock *) cp->info[(((pc)[1] << 8) | (pc)[2])];
                        arg1 = ostack - new_mb->args_count;
                        if (!*arg1) {
                            frame->last_pc = pc;
                            signalChainedExceptionEnum(exception_java_lang_NullPointerException, ((void *) 0),
                                                       ((void *) 0));
                            goto throwException;
                        };;
                        cb = ((ClassBlock *) ((*(Object **) arg1)->class + 1));
                        if (cache >= cb->imethod_table_size || new_mb->class != cb->imethod_table[cache].interface) {
                            for (cache = 0; cache < cb->imethod_table_size && new_mb->class !=
                                                                              cb->imethod_table[cache].interface; cache++);
                            if (cache == cb->imethod_table_size) {
                                frame->last_pc = pc;
                                signalChainedExceptionEnum(exception_java_lang_IncompatibleClassChangeError,
                                                           "unimplemented interface", ((void *) 0));
                                goto throwException;
                            };
                            ((pc + 3)[1]) = cache;
                        }
                        mtbl_idx = cb->imethod_table[cache].offsets[new_mb->method_table_index];
                        new_mb = cb->method_table[mtbl_idx];
                        goto invokeMethod;
                    }
                });
            case 233:
                ({
                    {
                        Class *class = ((Class *) cp->info[(((pc)[1] << 8) | (pc)[2])]);
                        Object *obj;
                        frame->last_pc = pc;
                        if ((obj = allocObject(class)) == ((void *) 0)) goto throwException;
                        {
                            uintptr_t tos = (uintptr_t) obj;
                            *ostack++ = tos;
                            {
                                pc += 3;
                                break;
                            };
                        };
                    }
                });
            case 235:
                ({
                    {
                        Class *class = ((Class *) cp->info[(((pc)[1] << 8) | (pc)[2])]);
                        int count = *--ostack;
                        Object *obj;
                        frame->last_pc = pc;
                        if (count < 0) {
                            signalChainedExceptionEnum(exception_java_lang_NegativeArraySizeException, ((void *) 0),
                                                       ((void *) 0));
                            goto throwException;
                        }
                        obj = allocObjectArray(class, count);
                        if (obj == ((void *) 0)) goto throwException;
                        {
                            uintptr_t tos = (uintptr_t) obj;
                            *ostack++ = tos;
                            {
                                pc += 3;
                                break;
                            };
                        };
                    }
                });
            case 238:
                ({
                    {
                        Class *class = ((Class *) cp->info[(((pc)[1] << 8) | (pc)[2])]);
                        Object *obj = (Object *) ostack[-1];
                        if ((obj != ((void *) 0)) && !isInstanceOf(class, obj->class)) {
                            frame->last_pc = pc;
                            signalChainedExceptionEnum(exception_java_lang_ClassCastException,
                                                       ((ClassBlock *) (obj->class + 1))->name, ((void *) 0));
                            goto throwException;
                        };
                        {
                            pc += 3;
                            break;
                        };
                    }
                });
            case 239:
                ({
                    {
                        Class *class = ((Class *) cp->info[(((pc)[1] << 8) | (pc)[2])]);
                        Object *obj = (Object *) ostack[-1];
                        if (obj != ((void *) 0)) ostack[-1] = isInstanceOf(class, obj->class);
                        {
                            pc += 3;
                            break;
                        };
                    }
                });
            case 243:
                ({
                    ({
                        Class *class = ((Class *) cp->info[(((pc)[1] << 8) | (pc)[2])]);
                        int i, dim = ((pc + 2)[1]);
                        Object *obj;
                        ostack -= dim;
                        frame->last_pc = pc;
                        for (i = 0; i < dim; i++)
                            if ((intptr_t) ostack[i] < 0) {
                                signalChainedExceptionEnum(exception_java_lang_NegativeArraySizeException, ((void *) 0),
                                                           ((void *) 0));
                                goto throwException;
                            }
                        if ((obj = allocMultiArray(class, dim, (intptr_t *) ostack)) == ((void *) 0))
                            goto throwException;
                        {
                            uintptr_t tos = (uintptr_t) obj;
                            *ostack++ = tos;
                            {
                                pc += 4;
                                break;
                            };
                        };
                    });
                });
            case 222:
                ({
                    {
                        frame->mb = mb = mb->miranda_mb;;
                        pc = (CodePntr) mb->code;
                        cp = &(((ClassBlock *) (mb->class + 1))->constant_pool);
                        {
                            pc += 0;
                            break;
                        }
                    }
                });
            case 223:
                ({
                    {
                        ee->last_frame = frame->prev;
                        if (mb->flags & 8) {
                            char buff[strlen(mb->name) + sizeof(": conflicting default methods")];
                            __builtin___strcat_chk(
                                    __builtin___strcpy_chk(buff, mb->name, __builtin_object_size(buff, 2 > 1 ? 1 : 0)),
                                    ": conflicting default methods", __builtin_object_size(
                                            __builtin___strcpy_chk(buff, mb->name,
                                                                   __builtin_object_size(buff, 2 > 1 ? 1 : 0)),
                                            2 > 1 ? 1 : 0));
                            signalChainedExceptionEnum(exception_java_lang_AbstractMethodError, buff, ((void *) 0));
                        } else
                            signalChainedExceptionEnum(exception_java_lang_AbstractMethodError, mb->name, ((void *) 0));
                        goto throwException;
                    }
                });
            case 214:
                ({
                    {
                        Class *new_class;
                        arg1 = ostack - ((pc + 1)[1]);
                        if (!*arg1) {
                            frame->last_pc = pc;
                            signalChainedExceptionEnum(exception_java_lang_NullPointerException, ((void *) 0),
                                                       ((void *) 0));
                            goto throwException;
                        };;
                        new_class = (*(Object **) arg1)->class;
                        new_mb = ((ClassBlock *) (new_class + 1))->method_table[((pc)[1])];
                        goto invokeMethod;
                    }
                });
            invokeMethod:
            {


                Frame *new_frame = (Frame *) (arg1 + new_mb->max_locals);
                Object *sync_ob = ((void *) 0);

                frame->last_pc = pc;
                ostack = (uintptr_t *) (((uintptr_t) (new_frame + 1) + 7) & ~7);

                if ((char *) (ostack + new_mb->max_stack) > ee->stack_end) {
                    if (ee->overflow++) {


                        jam_fprintf(__stdoutp, "Fatal stack overflow!  Aborting VM.\n");
                        exitVM(1);
                    }
                    ee->stack_end += 1 * 1024;
                    {
                        frame->last_pc = pc;
                        signalChainedExceptionEnum(exception_java_lang_StackOverflowError, ((void *) 0), ((void *) 0));
                        goto throwException;
                    };
                }

                new_frame->mb = new_mb;
                new_frame->lvars = arg1;
                new_frame->ostack = ostack;
                new_frame->prev = frame;

                ee->last_frame = new_frame;

                if (new_mb->access_flags & 0x0020) {
                    sync_ob = new_mb->access_flags & 0x0008 ? (Object *) new_mb->class
                                                            : (Object *) *arg1;
                    objectLock(sync_ob);
                }

                if (new_mb->access_flags & 0x0100) {
                    ClassBlock *cb = CLASS_CB(new_mb->class);
//                    jam_printf("native call %s.%s%s \n", cb->name, new_mb->name, new_mb->type);
                    ostack = (*new_mb->native_invoker)(new_mb->class, new_mb, arg1);

                    if (sync_ob)
                        objectUnlock(sync_ob);

                    ee->last_frame = frame;

                    if (ee->exception)
                        goto throwException;
                    {
                        pc += *pc >= 249 ? 5 : 3;
                        break;
                    };
                } else { ;
                    frame = new_frame;
                    mb = new_mb;
                    lvars = new_frame->lvars;
                    this = (Object *) lvars[0];
                    pc = (CodePntr) mb->code;
                    cp = &(((ClassBlock *) (mb->class + 1))->constant_pool);
                    ClassBlock *cb = CLASS_CB(mb->class);
//                    jam_printf("java call %s.%s%s \n", cb->name, mb->name, mb->type);
                }
                {
                    pc += 0;
                    break;
                }
            }

            methodReturn:

                frame = frame->prev;

                if (frame->mb == ((void *) 0)) {


                    return ostack;
                }

                if (mb->access_flags & 0x0020) {
                    Object *sync_ob = mb->access_flags & 0x0008 ? (Object *) mb->class
                                                                : this;
                    objectUnlock(sync_ob);
                }
                ClassBlock *cb = CLASS_CB(mb->class);
//                jam_printf("method ret %s.%s%s \n", cb->name, mb->name, mb->type);

                mb = frame->mb;
                ostack = lvars;
                lvars = frame->lvars;
                this = (Object *) lvars[0];
                pc = frame->last_pc;
                cp = &(((ClassBlock *) (mb->class + 1))->constant_pool);


                ee->last_frame = frame;

                {
                    pc += *pc >= 249 ? 5 : 3;
                    break;
                };
            throwException:
            {
                Object *excep = ee->exception;
                ee->exception = ((void *) 0);

                pc = findCatchBlock(excep->class);


                if (pc == ((void *) 0)) {
                    ee->exception = excep;
                    return ((void *) 0);
                }


                if (ee->overflow) {
                    ee->overflow = 0;
                    ee->stack_end -= 1 * 1024;
                }


                frame = ee->last_frame;
                mb = frame->mb;
                ostack = frame->ostack;
                lvars = frame->lvars;
                this = (Object *) lvars[0];
                cp = &(((ClassBlock *) (mb->class + 1))->constant_pool);

                *ostack++ = (uintptr_t) excep;


                {
                    pc += 0;
                    break;
                }
            }

        }
    }

}


int initialiseInterpreter(InitArgs *args) {


    return 1;
}

void shutdownInterpreter() {


}

