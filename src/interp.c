
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
            case OPC_ICONST_M1: {
                uintptr_t tos = -1;
                *ostack++ = tos;
                {
                    pc += 1;
                    break;
                };
            };
            case OPC_ICONST_0:
            case OPC_FCONST_0:
            case OPC_ACONST_NULL: {
                uintptr_t tos = 0;
                *ostack++ = tos;
                {
                    pc += 1;
                    break;
                };
            };
            case OPC_ICONST_1: {
                uintptr_t tos = 1;
                *ostack++ = tos;
                {
                    pc += 1;
                    break;
                };
            };
            case OPC_ICONST_2: {
                uintptr_t tos = 2;
                *ostack++ = tos;
                {
                    pc += 1;
                    break;
                };
            };
            case OPC_ICONST_3: {
                uintptr_t tos = 3;
                *ostack++ = tos;
                {
                    pc += 1;
                    break;
                };
            };
            case OPC_ICONST_4: {
                uintptr_t tos = 4;
                *ostack++ = tos;
                {
                    pc += 1;
                    break;
                };
            };
            case OPC_ICONST_5: {
                uintptr_t tos = 5;
                *ostack++ = tos;
                {
                    pc += 1;
                    break;
                };
            };
            case OPC_FCONST_1: {
                uintptr_t tos = 0x3f800000;
                *ostack++ = tos;
                {
                    pc += 1;
                    break;
                };
            };
            case OPC_FCONST_2: {
                uintptr_t tos = 0x40000000;
                *ostack++ = tos;
                {
                    pc += 1;
                    break;
                };
            };
            case OPC_SIPUSH: {
                uintptr_t tos = (signed short) (((pc)[1] << 8) | (pc)[2]);
                *ostack++ = tos;
                {
                    pc += 3;
                    break;
                };
            };
            case OPC_BIPUSH: {
                uintptr_t tos = (signed char) ((pc)[1]);
                *ostack++ = tos;
                {
                    pc += 2;
                    break;
                };
            };
            case OPC_LDC_QUICK: {
                uintptr_t tos = cp->info[((pc)[1])];
                *ostack++ = tos;
                {
                    pc += 2;
                    break;
                };
            };
            case OPC_LDC_W_QUICK: {
                uintptr_t tos = cp->info[(((pc)[1] << 8) | (pc)[2])];
                *ostack++ = tos;
                {
                    pc += 3;
                    break;
                };
            };
            case OPC_ILOAD:
            case OPC_FLOAD:
            case OPC_ALOAD: {
                uintptr_t tos = lvars[((pc)[1])];
                *ostack++ = tos;
                {
                    pc += 2;
                    break;
                };
            };
            case OPC_ALOAD_THIS:
                if (pc[1] != 180) {
                    int opcode;
                    if (pc[1] == 206) opcode = 229; else if (pc[1] == 217) opcode = 221; else opcode = 26;
                    pc[0] = opcode;
                    {
                        pc += 0;
                        break;
                    };
                };
            case OPC_ILOAD_0:
            case OPC_FLOAD_0: {
                uintptr_t tos = lvars[0];
                *ostack++ = tos;
                {
                    pc += 1;
                    break;
                };
            }
            case OPC_ILOAD_1:
            case OPC_FLOAD_1:
            case OPC_ALOAD_1: {
                uintptr_t tos = lvars[1];
                *ostack++ = tos;
                {
                    pc += 1;
                    break;
                };
            };
            case OPC_ILOAD_2:
            case OPC_FLOAD_2:
            case OPC_ALOAD_2: {
                uintptr_t tos = lvars[2];
                *ostack++ = tos;
                {
                    pc += 1;
                    break;
                };
            };
            case OPC_ILOAD_3:
            case OPC_FLOAD_3:
            case OPC_ALOAD_3: {
                uintptr_t tos = lvars[3];
                *ostack++ = tos;
                {
                    pc += 1;
                    break;
                };
            };
            case OPC_ISTORE:
            case OPC_FSTORE:
            case OPC_ASTORE:
                lvars[((pc)[1])] = *--ostack;
                {
                    pc += 2;
                    break;
                };;
            case OPC_ISTORE_0:
            case OPC_ASTORE_0:
            case OPC_FSTORE_0:
                lvars[0] = *--ostack;
                {
                    pc += 1;
                    break;
                };;
            case OPC_ISTORE_1:
            case OPC_ASTORE_1:
            case OPC_FSTORE_1:
                lvars[1] = *--ostack;
                {
                    pc += 1;
                    break;
                };;
            case OPC_ISTORE_2:
            case OPC_ASTORE_2:
            case OPC_FSTORE_2:
                lvars[2] = *--ostack;
                {
                    pc += 1;
                    break;
                };;
            case OPC_ISTORE_3:
            case OPC_ASTORE_3:
            case OPC_FSTORE_3:
                lvars[3] = *--ostack;
                {
                    pc += 1;
                    break;
                };;
            case OPC_IADD:
                ostack -= 2;
                {
                    uintptr_t tos = (int) ostack[0] + (int) ostack[1];
                    *ostack++ = tos;
                    {
                        pc += 1;
                        break;
                    };
                };;
            case OPC_ISUB:
                ostack -= 2;
                {
                    uintptr_t tos = (int) ostack[0] - (int) ostack[1];
                    *ostack++ = tos;
                    {
                        pc += 1;
                        break;
                    };
                };;
            case OPC_IMUL:
                ostack -= 2;
                {
                    uintptr_t tos = (int) ostack[0] * (int) ostack[1];
                    *ostack++ = tos;
                    {
                        pc += 1;
                        break;
                    };
                };;
            case OPC_IDIV:
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
            case OPC_IREM:
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
            case OPC_IAND:
                ostack -= 2;
                {
                    uintptr_t tos = (int) ostack[0] & (int) ostack[1];
                    *ostack++ = tos;
                    {
                        pc += 1;
                        break;
                    };
                };;
            case OPC_IOR:
                ostack -= 2;
                {
                    uintptr_t tos = (int) ostack[0] | (int) ostack[1];
                    *ostack++ = tos;
                    {
                        pc += 1;
                        break;
                    };
                };;
            case OPC_IXOR:
                ostack -= 2;
                {
                    uintptr_t tos = (int) ostack[0] ^(int) ostack[1];
                    *ostack++ = tos;
                    {
                        pc += 1;
                        break;
                    };
                };;
            case OPC_INEG: {
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
            case OPC_ISHL:
                ostack -= 2;
                {
                    uintptr_t tos = (int) ostack[0] << (ostack[1] & 0x1f);
                    *ostack++ = tos;
                    {
                        pc += 1;
                        break;
                    };
                };;
            case OPC_ISHR:
                ostack -= 2;
                {
                    uintptr_t tos = (int) ostack[0] >> (ostack[1] & 0x1f);
                    *ostack++ = tos;
                    {
                        pc += 1;
                        break;
                    };
                };;
            case OPC_IUSHR:
                ostack -= 2;
                {
                    uintptr_t tos = (unsigned int) ostack[0] >> (ostack[1] & 0x1f);
                    *ostack++ = tos;
                    {
                        pc += 1;
                        break;
                    };
                };;
            case OPC_IF_ICMPEQ:
            case OPC_IF_ACMPEQ:
                ostack -= 2;
                {
                    pc += ((int) ostack[0] == (int) ostack[1]) ? (signed short) (((pc)[1] << 8) | (pc)[2]) : 3;
                    break;
                };;
            case OPC_IF_ICMPNE:
            case OPC_IF_ACMPNE:
                ostack -= 2;
                {
                    pc += ((int) ostack[0] != (int) ostack[1]) ? (signed short) (((pc)[1] << 8) | (pc)[2]) : 3;
                    break;
                };;
            case OPC_IF_ICMPLT:
                ostack -= 2;
                {
                    pc += ((int) ostack[0] < (int) ostack[1]) ? (signed short) (((pc)[1] << 8) | (pc)[2]) : 3;
                    break;
                };;
            case OPC_IF_ICMPGE:
                ostack -= 2;
                {
                    pc += ((int) ostack[0] >= (int) ostack[1]) ? (signed short) (((pc)[1] << 8) | (pc)[2]) : 3;
                    break;
                };;
            case OPC_IF_ICMPGT:
                ostack -= 2;
                {
                    pc += ((int) ostack[0] > (int) ostack[1]) ? (signed short) (((pc)[1] << 8) | (pc)[2]) : 3;
                    break;
                };;
            case OPC_IF_ICMPLE:
                ostack -= 2;
                {
                    pc += ((int) ostack[0] <= (int) ostack[1]) ? (signed short) (((pc)[1] << 8) | (pc)[2]) : 3;
                    break;
                };;
            case OPC_IFNE:
            case OPC_IFNONNULL: {
                pc += ((int) *--ostack != 0) ? (signed short) (((pc)[1] << 8) | (pc)[2]) : 3;
                break;
            };;
            case OPC_IFEQ:
            case OPC_IFNULL: {
                pc += ((int) *--ostack == 0) ? (signed short) (((pc)[1] << 8) | (pc)[2]) : 3;
                break;
            };;
            case OPC_IFLT: {
                pc += ((int) *--ostack < 0) ? (signed short) (((pc)[1] << 8) | (pc)[2]) : 3;
                break;
            };;
            case OPC_IFGE: {
                pc += ((int) *--ostack >= 0) ? (signed short) (((pc)[1] << 8) | (pc)[2]) : 3;
                break;
            };;
            case OPC_IFGT: {
                pc += ((int) *--ostack > 0) ? (signed short) (((pc)[1] << 8) | (pc)[2]) : 3;
                break;
            };;
            case OPC_IFLE: {
                pc += ((int) *--ostack <= 0) ? (signed short) (((pc)[1] << 8) | (pc)[2]) : 3;
                break;
            };;
            case OPC_IINC:
                lvars[((pc)[1])] += (signed char) ((pc + 1)[1]);
                {
                    pc += 3;
                    break;
                };
            case OPC_POP:
                ostack--;
                {
                    pc += 1;
                    break;
                };;
            case OPC_POP2:
                ostack -= 2 - 0;
                {
                    pc += 1;
                    break;
                };
            case OPC_DUP: {
                uintptr_t tos = ostack[-1];
                *ostack++ = tos;
                {
                    pc += 1;
                    break;
                };
            };;
            case OPC_IRETURN:
            case OPC_ARETURN:
            case OPC_FRETURN:
                *lvars++ = *--ostack;
                goto methodReturn;;
            case OPC_RETURN:
                goto methodReturn;
            case OPC_GETSTATIC_QUICK: {
                uintptr_t tos = *(u4 *) (((FieldBlock *) cp->info[(((pc)[1] << 8) | (pc)[2])])->u.static_value.data);
                *ostack++ = tos;
                {
                    pc += 3;
                    break;
                };
            };
            case OPC_PUTSTATIC_QUICK:
                *(u4 *) (((FieldBlock *) cp->info[(((pc)[1] << 8) | (pc)[2])])->u.static_value.data) = *--ostack;
                {
                    pc += 3;
                    break;
                };;
            case OPC_GETFIELD_THIS: {
                uintptr_t tos = *(u4 *) &((char *) this)[((pc + 1)[1])];
                *ostack++ = tos;
                {
                    pc += 4;
                    break;
                };
            };
            case OPC_GETFIELD_QUICK: {
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
            case OPC_GETSTATIC_QUICK_REF: {
                uintptr_t tos = *(uintptr_t *) (((FieldBlock *) cp->info[(((pc)[1] << 8) |
                                                                          (pc)[2])])->u.static_value.data);
                *ostack++ = tos;
                {
                    pc += 3;
                    break;
                };
            };
            case OPC_PUTSTATIC_QUICK_REF:
                *(uintptr_t *) (((FieldBlock *) cp->info[(((pc)[1] << 8) | (pc)[2])])->u.static_value.data) = *--ostack;
                {
                    pc += 3;
                    break;
                };;
            case OPC_GETFIELD_THIS_REF: {
                uintptr_t tos = *(uintptr_t *) &((char *) this)[((pc + 1)[1])];
                *ostack++ = tos;
                {
                    pc += 4;
                    break;
                };
            };
            case OPC_GETFIELD_QUICK_REF: {
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


            case OPC_NOP:
                ({
                    {
                        pc += 1;
                        break;
                    };
                });
            case OPC_LCONST_0:
            case OPC_DCONST_0:
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


            case OPC_DCONST_1:
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


            case OPC_LCONST_1:
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


            case OPC_LDC2_W:
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


            case OPC_LLOAD:
            case OPC_DLOAD:
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


            case OPC_LLOAD_0:
            case OPC_DLOAD_0:
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


            case OPC_LLOAD_1:
            case OPC_DLOAD_1:
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


            case OPC_LLOAD_2:
            case OPC_DLOAD_2:
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


            case OPC_LLOAD_3:
            case OPC_DLOAD_3:
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
            case OPC_LSTORE:
            case OPC_DSTORE:
                *(u8 *) (&lvars[((pc)[1])]) = ({
                    ostack -= (sizeof(uint64_t) + 3) / 4;
                    *(uint64_t *) &ostack[0 * 2];
                });
                {
                    pc += 2;
                    break;
                };;


            case OPC_LSTORE_0:
            case OPC_DSTORE_0:
                *(u8 *) (&lvars[0]) = ({
                    ostack -= (sizeof(uint64_t) + 3) / 4;
                    *(uint64_t *) &ostack[0 * 2];
                });
                {
                    pc += 1;
                    break;
                };;


            case OPC_LSTORE_1:
            case OPC_DSTORE_1:
                *(u8 *) (&lvars[1]) = ({
                    ostack -= (sizeof(uint64_t) + 3) / 4;
                    *(uint64_t *) &ostack[0 * 2];
                });
                {
                    pc += 1;
                    break;
                };;


            case OPC_LSTORE_2:
            case OPC_DSTORE_2:
                *(u8 *) (&lvars[2]) = ({
                    ostack -= (sizeof(uint64_t) + 3) / 4;
                    *(uint64_t *) &ostack[0 * 2];
                });
                {
                    pc += 1;
                    break;
                };;


            case OPC_LSTORE_3:
            case OPC_DSTORE_3:
                *(u8 *) (&lvars[3]) = ({
                    ostack -= (sizeof(uint64_t) + 3) / 4;
                    *(uint64_t *) &ostack[0 * 2];
                });
                {
                    pc += 1;
                    break;
                };;
            case OPC_IALOAD:
            case OPC_FALOAD: {
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


            case OPC_AALOAD: {
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


            case OPC_BALOAD: {
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


            case OPC_CALOAD: {
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


            case OPC_SALOAD: {
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


            case OPC_LALOAD:
            case OPC_DALOAD: {
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
            case OPC_IASTORE:
            case OPC_FASTORE: {
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


            case OPC_BASTORE: {
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


            case OPC_CASTORE:
            case OPC_SASTORE: {
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


            case OPC_AASTORE: {
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
            case OPC_LASTORE:
            case OPC_DASTORE: {
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
            case OPC_DUP_X1: {
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
            case OPC_DUP_X2: {
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
            case OPC_DUP2: {
                ostack[0] = ostack[-2];
                ostack[1] = ostack[-1];
                ostack += 2;
                {
                    pc += 1;
                    break;
                };
            }


            case OPC_DUP2_X1: {
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
            case OPC_DUP2_X2: {
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
            case OPC_SWAP: {
                uintptr_t word1 = ostack[-1];
                ostack[-1] = ostack[-2];
                ostack[-2] = word1;
                {
                    pc += 1;
                    break;
                }
            }
            case OPC_FADD:
                ({
                    *((float *) &ostack[-2] + (sizeof(uintptr_t) == 8 && 0)) += *((float *) &ostack[-1] +
                                                                                  (sizeof(uintptr_t) == 8 && 0));
                    ostack -= (sizeof(float) + 3) / 4;
                    {
                        pc += 1;
                        break;
                    };;
                });


            case OPC_DADD:
                ({
                    *(double *) &ostack[-2 * 2] += *(double *) &ostack[-1 * 2];
                    ostack -= (sizeof(double) + 3) / 4;
                    {
                        pc += 1;
                        break;
                    };;
                });


            case OPC_FSUB:
                ({
                    *((float *) &ostack[-2] + (sizeof(uintptr_t) == 8 && 0)) -= *((float *) &ostack[-1] +
                                                                                  (sizeof(uintptr_t) == 8 && 0));
                    ostack -= (sizeof(float) + 3) / 4;
                    {
                        pc += 1;
                        break;
                    };;
                });


            case OPC_DSUB:
                ({
                    *(double *) &ostack[-2 * 2] -= *(double *) &ostack[-1 * 2];
                    ostack -= (sizeof(double) + 3) / 4;
                    {
                        pc += 1;
                        break;
                    };;
                });


            case OPC_FMUL:
                ({
                    *((float *) &ostack[-2] + (sizeof(uintptr_t) == 8 && 0)) *= *((float *) &ostack[-1] +
                                                                                  (sizeof(uintptr_t) == 8 && 0));
                    ostack -= (sizeof(float) + 3) / 4;
                    {
                        pc += 1;
                        break;
                    };;
                });


            case OPC_DMUL:
                ({
                    *(double *) &ostack[-2 * 2] *= *(double *) &ostack[-1 * 2];
                    ostack -= (sizeof(double) + 3) / 4;
                    {
                        pc += 1;
                        break;
                    };;
                });


            case OPC_FDIV:
                ({
                    *((float *) &ostack[-2] + (sizeof(uintptr_t) == 8 && 0)) /= *((float *) &ostack[-1] +
                                                                                  (sizeof(uintptr_t) == 8 && 0));
                    ostack -= (sizeof(float) + 3) / 4;
                    {
                        pc += 1;
                        break;
                    };;
                });


            case OPC_DDIV:
                ({
                    *(double *) &ostack[-2 * 2] /= *(double *) &ostack[-1 * 2];
                    ostack -= (sizeof(double) + 3) / 4;
                    {
                        pc += 1;
                        break;
                    };;
                });
            case OPC_LADD:
                *(int64_t *) &ostack[-2 * 2] += *(int64_t *) &ostack[-1 * 2];
                ostack -= (sizeof(int64_t) + 3) / 4;
                {
                    pc += 1;
                    break;
                };;


            case OPC_LSUB:
                *(int64_t *) &ostack[-2 * 2] -= *(int64_t *) &ostack[-1 * 2];
                ostack -= (sizeof(int64_t) + 3) / 4;
                {
                    pc += 1;
                    break;
                };;


            case OPC_LMUL:
                *(int64_t *) &ostack[-2 * 2] *= *(int64_t *) &ostack[-1 * 2];
                ostack -= (sizeof(int64_t) + 3) / 4;
                {
                    pc += 1;
                    break;
                };;


            case OPC_LAND:
                *(int64_t *) &ostack[-2 * 2] &= *(int64_t *) &ostack[-1 * 2];
                ostack -= (sizeof(int64_t) + 3) / 4;
                {
                    pc += 1;
                    break;
                };;


            case OPC_LOR:
                *(int64_t *) &ostack[-2 * 2] |= *(int64_t *) &ostack[-1 * 2];
                ostack -= (sizeof(int64_t) + 3) / 4;
                {
                    pc += 1;
                    break;
                };;


            case OPC_LXOR:
                *(int64_t *) &ostack[-2 * 2] ^= *(int64_t *) &ostack[-1 * 2];
                ostack -= (sizeof(int64_t) + 3) / 4;
                {
                    pc += 1;
                    break;
                };;
            case OPC_LDIV:
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


            case OPC_LREM:
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
            case OPC_LSHL: {
                int shift = *--ostack & 0x3f;
                *(int64_t *) &ostack[-1 * 2] <<= shift;
                {
                    pc += 1;
                    break;
                };
            };


            case OPC_LSHR: {
                int shift = *--ostack & 0x3f;
                *(int64_t *) &ostack[-1 * 2] >>= shift;
                {
                    pc += 1;
                    break;
                };
            };


            case OPC_LUSHR: {
                int shift = *--ostack & 0x3f;
                *(uint64_t *) &ostack[-1 * 2] >>= shift;
                {
                    pc += 1;
                    break;
                };
            };
            case OPC_FREM:
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


            case OPC_DREM:
                ({
                    *(double *) &ostack[-2 * 2] = fmod(*(double *) &ostack[-2 * 2], *(double *) &ostack[-1 * 2]);
                    ostack -= (sizeof(double) + 3) / 4;
                    {
                        pc += 1;
                        break;
                    };;
                });


            case OPC_FNEG:
                ({
                    *((float *) &ostack[-1] + (sizeof(uintptr_t) == 8 && 0)) = -*((float *) &ostack[-1] +
                                                                                  (sizeof(uintptr_t) == 8 && 0));
                    {
                        pc += 1;
                        break;
                    };;
                });


            case OPC_DNEG:
                ({
                    *(double *) &ostack[-1 * 2] = -*(double *) &ostack[-1 * 2];
                    {
                        pc += 1;
                        break;
                    };;
                });


            case OPC_LNEG:
                *(int64_t *) &ostack[-1 * 2] = -*(int64_t *) &ostack[-1 * 2];
                {
                    pc += 1;
                    break;
                };;
            case OPC_L2I: {
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
            case OPC_I2F:
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


            case OPC_I2D:
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


            case OPC_L2F:
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


            case OPC_L2D:
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


            case OPC_F2D:
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


            case OPC_D2F:
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
            case OPC_F2I:
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


            case OPC_D2I:
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
            case OPC_F2L:
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


            case OPC_D2L:
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


            case OPC_I2L:
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


            case OPC_I2B:
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


            case OPC_I2C:
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


            case OPC_I2S:
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


            case OPC_LCMP: {
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
            case OPC_DCMPG:
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


            case OPC_DCMPL:
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


            case OPC_FCMPG:
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


            case OPC_FCMPL:
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


            case OPC_GOTO:
                ({
                    ({
                        {
                            pc += (1) ? (signed short) (((pc)[1] << 8) | (pc)[2]) : 3;
                            break;
                        };
                    });
                });

            case OPC_JSR:
                ({
                    ({
                        *ostack++ = (uintptr_t) pc;
                        {
                            pc += (1) ? (signed short) (((pc)[1] << 8) | (pc)[2]) : 3;
                            break;
                        };
                    });
                });


            case OPC_RET:
                ({
                    pc = (CodePntr) lvars[((pc)[1])];
                    {
                        pc += 3;
                        break;
                    };
                });


            case OPC_LRETURN:
            case OPC_DRETURN:
                *(u8 *) lvars = ({
                    ostack -= (sizeof(uint64_t) + 3) / 4;
                    *(uint64_t *) &ostack[0 * 2];
                });
                lvars += 2;
                goto methodReturn;
            case OPC_ARRAYLENGTH:
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


            case OPC_ATHROW:
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
            case OPC_NEWARRAY:
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
            case OPC_MONITORENTER:
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


            case OPC_MONITOREXIT:
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
            case OPC_LDC:
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
            case OPC_LDC_W:
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
            case OPC_ALOAD_0:
                ({
                    {
                        if (mb->access_flags & 0x0008) pc[0] = 26; else pc[0] = 231;
                        {
                            pc += 0;
                            break;
                        };
                    }
                });


            case OPC_TABLESWITCH:
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
            case OPC_LOOKUPSWITCH:
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
            case OPC_GETSTATIC:
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
            case OPC_PUTSTATIC:
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
            case OPC_GETFIELD:
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
            case OPC_PUTFIELD:
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
            case OPC_GETFIELD_QUICK_W:
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
            case OPC_PUTFIELD_QUICK_W: {
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
            case OPC_INVOKEVIRTUAL:
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
            case OPC_INVOKEVIRTUAL_QUICK_W:
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
            case OPC_INVOKESPECIAL:
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
            case OPC_INVOKEINTERFACE:
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
            case OPC_ANEWARRAY:
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
            case OPC_CHECKCAST:
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
            case OPC_INSTANCEOF:
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
            case OPC_MULTIANEWARRAY:
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

            case OPC_NEW:
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
            case OPC_WIDE:
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
            case OPC_GOTO_W:
                ({
                    {
                        {
                            pc += (signed int) (((pc)[1] << 24) | ((pc)[2] << 16) | ((pc)[3] << 8) | (pc)[4]);
                            break;
                        };
                    }
                });


            case OPC_JSR_W:
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


            case OPC_LOCK:
                ({
                    {
                        {
                            pc += 0;
                            break;
                        };
                    }
                });


            case OPC_GETSTATIC2_QUICK:
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


            case OPC_PUTSTATIC2_QUICK: {
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


            case OPC_GETFIELD2_QUICK:
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
            case OPC_PUTFIELD2_QUICK: {
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
            case OPC_PUTFIELD_QUICK: {
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
            case OPC_PUTFIELD_QUICK_REF: {
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

            case OPC_INVOKESUPER_QUICK:
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


            case OPC_INVOKENONVIRTUAL_QUICK:
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


            case OPC_INVOKESTATIC_QUICK:
                ({
                    {
                        new_mb = ((MethodBlock *) cp->info[(((pc)[1] << 8) | (pc)[2])]);
                        arg1 = ostack - new_mb->args_count;
                        goto invokeMethod;
                    }
                });


            case OPC_INVOKEINTERFACE_QUICK:
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
            case OPC_NEW_QUICK:
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
            case OPC_ANEWARRAY_QUICK:
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
            case OPC_CHECKCAST_QUICK:
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
            case OPC_INSTANCEOF_QUICK:
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
            case OPC_MULTIANEWARRAY_QUICK:
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
            case OPC_MIRANDA_BRIDGE:
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
            case OPC_ABSTRACT_METHOD_ERROR:
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
            case OPC_INVOKEVIRTUAL_QUICK:
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
                /* Create new frame first.  This is also created for natives
                   so that they appear correctly in the stack trace */

                Frame *new_frame = (Frame *) (arg1 + new_mb->max_locals);
                Object *sync_ob = NULL;

                frame->last_pc = pc;
                ostack = ALIGN_OSTACK(new_frame + 1);

                if ((char *) (ostack + new_mb->max_stack) > ee->stack_end) {
                    if (ee->overflow++) {
                        /* Overflow when we're already throwing stack overflow.
                           Stack extension should be enough to throw exception,
                           so something's seriously gone wrong - abort the VM! */
                        jam_fprintf(__stdoutp, "Fatal stack overflow!  Aborting VM.\n");
                        exitVM(1);
                    }
                    ee->stack_end += STACK_RED_ZONE_SIZE;
                    THROW_EXCEPTION(java_lang_StackOverflowError, NULL);
                }

                new_frame->mb = new_mb;
                new_frame->lvars = arg1;
                new_frame->ostack = ostack;
                new_frame->prev = frame;

                ee->last_frame = new_frame;

                if (new_mb->access_flags & ACC_SYNCHRONIZED) {
                    sync_ob = new_mb->access_flags & ACC_STATIC ? (Object *) new_mb->class
                                                            : (Object *) *arg1;
                    objectLock(sync_ob);
                }

                if (new_mb->access_flags & ACC_NATIVE) {
                    ClassBlock *cb = CLASS_CB(new_mb->class);
//                    jam_printf("native call %s.%s%s \n", cb->name, new_mb->name, new_mb->type);
                    ostack = (*new_mb->native_invoker)(new_mb->class, new_mb, arg1);

                    if (sync_ob)
                        objectUnlock(sync_ob);

                    ee->last_frame = frame;

                    if (ee->exception)
                        goto throwException;
                    DISPATCH(0, *pc >= OPC_INVOKEINTERFACE_QUICK ? 5 : 3);
                } else { ;
                    frame = new_frame;
                    mb = new_mb;
                    lvars = new_frame->lvars;
                    this = (Object *) lvars[0];
                    pc = (CodePntr) mb->code;
//                    cp = &(CLASS_CB(mb->class)->constant_pool);
                    cp = &(((ClassBlock *) (mb->class + 1))->constant_pool);
                    ClassBlock *cb = CLASS_CB(mb->class);
//                    jam_printf("java call %s.%s%s \n", cb->name, mb->name, mb->type);
                }
                DISPATCH_FIRST
            }

            methodReturn:
                /* Set interpreter state to previous frame */
                frame = frame->prev;

                if (frame->mb == NULL) {
                    /* The previous frame is a dummy frame - this indicates
                       top of this Java invocation. */
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

