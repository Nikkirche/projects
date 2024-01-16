cmd_/media/sf_hw4/Module.symvers := sed 's/\.ko$$/\.o/' /media/sf_hw4/modules.order | scripts/mod/modpost -m -a  -o /media/sf_hw4/Module.symvers -e -i Module.symvers   -T -
