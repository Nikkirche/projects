cmd_/media/sf_hw4/modules.order := {   echo /media/sf_hw4/networkfs.ko; :; } | awk '!x[$$0]++' - > /media/sf_hw4/modules.order
