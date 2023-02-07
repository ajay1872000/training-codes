cmd_/home/engineer/Desktop/c/kernel/modules.order := {   echo /home/engineer/Desktop/c/kernel/basicdriver.ko; :; } | awk '!x[$$0]++' - > /home/engineer/Desktop/c/kernel/modules.order
