#include<stdio.h>
main()
{
int n,val=0,rem,i;
printf("enter the number");
scanf("%d",&n);
while (n>0)
{
rem=n%10;
n=n/10;
val=(val*10)+rem;
i=val;
}
printf("%d",val);

//printf("%d",i);
}

 while (rem=i%10,i/10)

{
//scanf("%d",&rem);
case 1:
       printf("one");
     break;
case 2:
       printf("two");
     break;
case 3:
       printf("three");
     break;

     
case 4:
       printf("four");
      break;
case 5:
       printf("five");
     break;
case 6:
       printf("six");
     break;
case 7:
       printf("seven");
      break;  
case 8:
       printf("eight");
      break;
case 9:
       printf("nine");
  }                            
                                                                                                                                                                                                                                                                                                                                                                                  strict-overflow -fconserve-stack -DCC_HAVE_ASM_GOTO  -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(lab2_block.mod)"  -D"KBUILD_MODNAME=KBUILD_STR(lab2_block)" -DMODULE  -c -o /home/viven/Desktop/DDExercises/bdevs_35/lab2_block.mod.o /home/viven/Desktop/DDExercises/bdevs_35/lab2_block.mod.c

source_/home/viven/Desktop/DDExercises/bdevs_35/lab2_block.mod.o := /home/viven/Desktop/DDExercises/bdevs_35/lab2_block.mod.c

deps_/home/viven/Desktop/DDExercises/bdevs_35/lab2_block.mod.o := \
    $(wildcard include/config/module/unload.h) \
  include/linux/module.h \
    $(wildcard include/config/symbol/prefix.h) \
    $(wildcard include/config/sysfs.h) \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/modversions.h) \
    $(wildcard include/config/unused/symbols.h) \
    $(wildcard include/config/generic/bug.h) \
    $(wildcard include/config/kallsyms.h) \
    $(wildcard include/config/smp.h) \
    $(wildcard include/config/tracepoints.h) \
    $(wildcard include/config/tracing.h) \
    $(wildcard include/config/event/tracing.h) \
    $(wildcard include/config/ftrace/mcount/record.h) \
    $(wildcard include/config/constructors.h) \
    $(wildcard include/config/debug/set/module/ronx.h) \
  include/linux/list.h \
    $(wildcard include/config/debug/list.h) \
  include/linux/types.h \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/lbdaf.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
    $(wildcard include/config/64bit.h) \
  /usr/src/linux-headers-2.6.38-8-generic/arch/x86/include/asm/types.h \
    $(wildcard include/config/x86/64.h) \
    $(wildcard include/config/highmem64g.h) \
  include/asm-generic/types.h \
  include/asm-generic/int-ll64.h \
  /usr/src/linux-headers-2.6.38-8-generic/arch/x86/include/asm/bitsperlong.h \
  include/asm-generic/bitsperlong.h \
  include/linux/posix_types.h \
  include/linux/stddef.h \
  include/linux/compiler.h \
    $(wildcard include/config/sparse/rcu/pointer.h) \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
  include/linux/compiler-gcc4.h \
  /usr/src/linux-headers-2.6.38-8-generic/arch/x86/include/asm/posix_types.h \
    $(wildcard include/config/x86/32.h) \
  /usr/src/linux-headers-2.6.38-8-generic/arch/x86/include/asm/posix_types_32.h \
  include/linux/poison.h \
    $(wildcard include/config/illegal/pointer/value.h) \
  include/linux/prefetch.h \
  /usr/src/linux-headers-2.6.38-8-generic/arch/x86/include/asm/processor.h \
    $(wildcard include/config/x86/vsmp.h) \
    $(wildcard include/config/cc/stackprotector.h) \
    $(wildcard include/config/paravirt.h) \
    $(wildcard include/config/m386.h) \
    $(wildcard include/config/m486.h) \
    $(wildcard include/config/x86/debugctlmsr.h) \
    $(wildcard include/config/cpu/sup/amd.h) \
  /usr/src/linux-headers-2.6.38-8-generic/arch/x86/include/asm/processor-flags.h \
    $(wildcard include/config/vm86.h) \
  /usr/src/linux-headers-2.6.38-8-generic/arch/x86/include/asm/vm86.h \
  /usr/src/linux-headers-2.6.38-8-generic/arch/x86/include/asm/ptrace.h \
  /usr/src/linux-headers-2.6.38-8-generic/arch/x86/include/asm/ptrace-abi.h \
  /usr/src/linux-headers-2.6.38-8-generic/arch/x86/include/asm/segment.h \
  /usr/src/linux-headers-2.6.38-8-generic/arch/x86/include/asm/page_types.h \
  include/linux/const.h \
  /usr/src/linux-headers-2.6.38-8-generic/arch/x86/include/asm/page_32_types.h \
    $(wildcard include/config/highmem4g.h) \
    $(wildcard include/config/page/offset.h) \
    $(wildcard include/config/x86/pae.h) \
  include/linux/init.h \
    $(wildcard include/config/hotplug.h) \
  /usr/src/linux-headers-2.6.38-8-generic/arch/x86/include/asm/math_emu.h \
  /usr/src/linux-headers-2.6.38-8-generic/arch/x86/include/asm/sigcontext.h \
  /usr/src/linux-headers-2.6.38-8-generic/arch/x86/include/asm/current.h \
  /usr/src/linux-headers-2.6.38-8-generic/arch/x86/include/asm/percpu.h \
    $(wildcard include/config/x86/64/smp.h) \
  include/linux/kernel.h \
    $(wildcard include/config/preempt/voluntary.h) \
    $(wildcard include/config/debug/spinlock/sleep.h) \
    $(wildcard include/config/prove/locking.h) \
    $(wildcard include/config/ring/buffer.h) \
    $(wildcard include/config/numa.h) \
    $(wildcard include/config/compaction.h) \
  /usr/lib/i386-linux-gnu/gcc/i686-linux-gnu/4.5.2/include/stdarg.h \
  include/linux/linkage.h \
  /usr/src/linux-headers-2.6.38-8-generic/arch/x86/include/asm/linkage.h \
    $(wildcard include/config/x86/alignment/16.h) \
  include/linux/stringify.h \
  include/linux/bitops.h \
    $(wildcard include/config/generic/find/last/bit.h) \
  /usr/src/linux-headers-2.6.38-8-generic/arch/x86/include/asm/bitops.h \
    $(wildcard include/config/x86/cmov.h) \
  /usr/src/linux-headers-2.6.38-8-generic/arch/x86/include/asm/alternative.h \
    $(wildcard include/config/dynamic/ftrace.h) \
  include/linux/jump_label.h \
    $(wildcard include/config/jump/label.h) \
  /usr/src/linux-headers-2.6.38-8-generic/arch/x86/include/asm/jump_label.h \
  /usr/src/linux-headers-2.6.38-8-generic/arch/x86/include/asm/nops.h \
    $(wildcard include/config/mk7.h) \
    $(wildcard include/config/x86/p6/nop.h) \
  /usr/src/linux-headers-2.6.38-8-generic/arch/x86/include/asm/asm.h \
  /usr/src/linux-headers-2.6.38-8-generic/arch/x86/include/asm/cpufeature.h \
    $(wildcard include/config/x86/invlpg.h) \
  /usr/src/linux-headers-2.6.38-8-generic/arch/x86/include/asm/required-features.h \
    $(wildcard include/config/x86/minimum/cpu/family.h) \
    $(wildcard include/config/math/emulation.h) \
    $(wildcard include/config/x86/cmpxchg64.h) \
    $(wildcard include/config/x86/use/3dnow.h) \
  include/asm-generic/bitops/find.h \
    $(wildcard include/config/generic/find/first/bit.h) \
  include/asm-generic/bitops/sched.h \
  /usr/src/linux-headers-2.6.38-8-generic/arch/x86/include/asm/arch_hweight.h \
  include/asm-generic/bitops/const_hweight.h \
  include/asm-generic/bitops/fls64.h \
  include/asm-generic/bitops/ext2-non-atomic.h \
  include/asm-generic/bitops/le.h \
  /usr/src/linux-headers-2.6.38-8-generic/arch/x86/include/asm/byteorder.h \
  include/linux/byteorder/little_endian.h \
  include/linux/swab.h \
  /usr/src/linux-headers-2.6.38-8-generic/arch/x86/include/asm/swab.h \
    $(wildcard include/config/x86/bswap.h) \
  include/linux/byteorder/generic.h \
  include/asm-generic/bitops/minix.h \
  include/linux/log2.h \
    $(wildcard include/config/arch/has/ilog2/u32.h) \
    $(wildcard include/config/arch/has/ilog2/u64.h) \
  include/linux/typecheck.h \
  include/linux/printk.h \
    $(wildcard include/config/printk.h) \
    $(wildcard include/config/dynamic/debug.h) \
  include/linux/dynamic_debug.h \
  /usr/src/linux-headers-2.6.38-8-generic/arch/x86/include/asm/bug.h \
    $(wildcard include/config/bug.h) \
    $(wildcard include/config/debug/bugver