 # cs1730 paths
 #export GCC_HOME=/usr/local/gcc/10.1.0
 #export GDB_HOME=/usr/local/gdb/9.2

 # update link library path
 #export LD_LIBRARY_PATH=$GCC_HOME/lib64:$LD_LIBRARY_PATH

# update exec paths
#export PATH=$GDB_HOME/bin:$PATH
#export PATH=$GCC_HOME/bin:$PATH




########################
# .bash_profile
CS1302=/usr/local/mepcott/cs1302.profile; [[ -f $CS1302 ]] && . $CS1302
# Get the aliases and functions
if [ -f ~/.bashrc ]; then
	. ~/.bashrc
fi

# User specific environment and startup programs

PATH=$PATH:$HOME/.local/bin:$HOME/bin

##export PATH

export GCC_HOME=/usr/local/gcc/10.1.0
export GDB_HOME=/usr/local/gdb/9.2

export LD_LIBRARY_PATH=$GCC_HOME/lib64:$LD_LIBRARY_PATH

export PATH=$GDB_HOME/bin:$PATH
export PATH=$GCC_HOME/bin:$PATH
########