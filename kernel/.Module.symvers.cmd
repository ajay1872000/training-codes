cmd_/home/engineer/Desktop/c/kernel/Module.symvers := sed 's/ko$$/o/' /home/engineer/Desktop/c/kernel/modules.order | scripts/mod/modpost -m -a  -o /home/engineer/Desktop/c/kernel/Module.symvers -e -i Module.symvers   -T -