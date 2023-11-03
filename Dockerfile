#
# Process this Dockerfile with:
#
#     docker build -t taste:bullseye .
#
# And then run a fresh TASTE container with proper X11 redirection, with...
#
#     ./Docker-run.sh
#     docker attach taste
#
FROM debian:bullseye
RUN apt update
RUN apt -y install netcat net-tools wget lsb-release python3-pexpect
# libfuse is needed to run AppImage files (e.g. Space Creator)
RUN apt -y install libfuse2 libgl1-mesa-dev
# There is immense waste of re-downloading the .deb files
# in every attempt to setup the Docker image.
# The following uses a locally-provided proxy
# that will make sure the .deb files are only downloaded once,
# and are re-used in all subsequent attempts to build the image.
RUN route -n | awk '/^0.0.0.0/ {print $2}' > /tmp/host_ip.txt
RUN echo "HEAD /" | nc `cat /tmp/host_ip.txt` 8000 | grep squid-deb-proxy \
  && (echo "Acquire::http::Proxy \"http://$(cat /tmp/host_ip.txt):8000\";" > /etc/apt/apt.conf.d/30proxy) \
  && (echo "Acquire::http::Proxy::ppa.launchpad.net DIRECT;" >> /etc/apt/apt.conf.d/30proxy) \
  || echo "No squid-deb-proxy detected on docker host"
RUN bash -c 'export DEBIAN_FRONTEND=noninteractive ; apt-get -y install git sudo'
RUN bash -c 'cd /root ; git clone https://gitrepos.estec.esa.int/taste/taste-setup.git tool-src'
RUN bash -c 'cd /root/tool-src ; git checkout -f feature_bullseye'

# The following pieces correspond to the execution of Update-TASTE.sh ;
# but the execution has to be broken down into steps, so that Docker
# can resume the build from whichever step failed in the last attempt.
RUN bash -c 'cd /root/tool-src ; git submodule init ; git submodule update'
RUN bash -c 'cd /root/tool-src ; PATH=/root/tool-inst/bin:$PATH HOME=/root DISABLE_TASTE_BANNER=1 install/01_sudo.sh'
RUN bash -c 'cd /root/tool-src ; PATH=/root/tool-inst/bin:$PATH HOME=/root DISABLE_TASTE_BANNER=1 install/03_debian.sh'
RUN bash -c 'cd /root/tool-src ; PATH=/root/tool-inst/bin:$PATH HOME=/root DISABLE_TASTE_BANNER=1 install/04_pythonlibs.sh'
RUN bash -c 'cd /root/tool-src ; PATH=/root/tool-inst/bin:$PATH HOME=/root DISABLE_TASTE_BANNER=1 install/05_antlr.sh'
RUN bash -c 'cd /root/tool-src ; PATH=/root/tool-inst/bin:$PATH HOME=/root DISABLE_TASTE_BANNER=1 install/06_stlink.sh'
RUN bash -c 'cd /root/tool-src ; PATH=/root/tool-inst/bin:$PATH HOME=/root DISABLE_TASTE_BANNER=1 install/10_dmt.sh'
RUN bash -c 'cd /root/tool-src ; PATH=/root/tool-inst/bin:$PATH HOME=/root DISABLE_TASTE_BANNER=1 install/15_asn1scc.sh'
RUN bash -c 'cd /root/tool-src ; PATH=/root/tool-inst/bin:$PATH HOME=/root DISABLE_TASTE_BANNER=1 install/16_cleanup-old-mscc.sh'
RUN bash -c 'cd /root/tool-src ; PATH=/root/tool-inst/bin:$PATH HOME=/root DISABLE_TASTE_BANNER=1 install/20_msc.sh'
RUN bash -c 'cd /root/tool-src ; PATH=/root/tool-inst/bin:$PATH HOME=/root DISABLE_TASTE_BANNER=1 install/30_qemu.sh'
RUN bash -c 'cd /root/tool-src ; PATH=/root/tool-inst/bin:$PATH HOME=/root DISABLE_TASTE_BANNER=1 install/39_tasteconfig.sh'
RUN bash -c 'cd /root/tool-src ; PATH=/root/tool-inst/bin:$PATH HOME=/root DISABLE_TASTE_BANNER=1 install/40_ocarina.sh'
RUN bash -c 'cd /root/tool-src ; PATH=/root/tool-inst/bin:$PATH HOME=/root DISABLE_TASTE_BANNER=1 install/45_pohi.sh'
RUN bash -c 'cd /root/tool-src ; PATH=/root/tool-inst/bin:$PATH HOME=/root DISABLE_TASTE_BANNER=1 install/46_aadlib.sh'
RUN bash -c 'cd /root/tool-src ; PATH=/root/tool-inst/bin:$PATH HOME=/root DISABLE_TASTE_BANNER=1 install/50_opengeode.sh'
RUN bash -c 'cd /root/tool-src ; PATH=/root/tool-inst/bin:$PATH HOME=/root DISABLE_TASTE_BANNER=1 install/53_pymsc.sh'
RUN bash -c 'cd /root/tool-src ; PATH=/root/tool-inst/bin:$PATH HOME=/root DISABLE_TASTE_BANNER=1 install/54_speedometer.sh'
RUN bash -c 'cd /root/tool-src ; PATH=/root/tool-inst/bin:$PATH HOME=/root DISABLE_TASTE_BANNER=1 install/55_asn1valueEditor.sh'
RUN bash -c 'cd /root/tool-src ; PATH=/root/tool-inst/bin:$PATH HOME=/root DISABLE_TASTE_BANNER=1 install/56_msc-editor.sh'
RUN bash -c 'cd /root/tool-src ; PATH=/root/tool-inst/bin:$PATH HOME=/root DISABLE_TASTE_BANNER=1 install/60_buildsupport.sh'
# Those that need postgres can set it up themselves (avoid creating huge Docker image)
# RUN bash -c 'cd /root/tool-src ; PATH=/root/tool-inst/bin:$PATH HOME=/root DISABLE_TASTE_BANNER=1 install/65_postgres.sh'
RUN bash -c 'cd /root/tool-src ; PATH=/root/tool-inst/bin:$PATH HOME=/root DISABLE_TASTE_BANNER=1 install/70_taste-model-checker.sh'
RUN bash -c 'cd /root/tool-src ; PATH=/root/tool-inst/bin:$PATH HOME=/root DISABLE_TASTE_BANNER=1 install/80_build-scripts.sh'
# Those that need RTEMS can set it up themselves (avoid creating huge Docker image)
# RUN bash -c 'cd /root/tool-src ; PATH=/root/tool-inst/bin:$PATH HOME=/root DISABLE_TASTE_BANNER=1 install/85_rtems.sh'
# RUN bash -c 'cd /root/tool-src ; PATH=/root/tool-inst/bin:$PATH HOME=/root DISABLE_TASTE_BANNER=1 install/86_air.sh'
RUN bash -c 'cd /root/tool-src ; PATH=/root/tool-inst/bin:$PATH HOME=/root DISABLE_TASTE_BANNER=1 install/87_kazoo.sh'
RUN bash -c 'cd /root/tool-src ; PATH=/root/tool-inst/bin:$PATH HOME=/root DISABLE_TASTE_BANNER=1 install/88_spaceCreator.sh'
RUN bash -c 'cd /root/tool-src ; PATH=/root/tool-inst/bin:$PATH HOME=/root DISABLE_TASTE_BANNER=1 install/89_linux_runtime.sh'
RUN bash -c 'cd /root/tool-src ; ./install/89_linux_runtime.sh'
RUN bash -c 'cd /root/tool-src ; PATH=/root/tool-inst/bin:$PATH HOME=/root DISABLE_TASTE_BANNER=1 install/90_misc.sh'
RUN bash -c 'cd /root/tool-src ; PATH=/root/tool-inst/bin:$PATH HOME=/root DISABLE_TASTE_BANNER=1 install/91_env.sh'
RUN bash -c 'cd /root/tool-src ; PATH=/root/tool-inst/bin:$PATH HOME=/root DISABLE_TASTE_BANNER=1 install/95_components_library.sh'
RUN bash -c 'cd /bin ; sudo rm sh ; sudo ln -s bash sh'
RUN bash -c 'cd /root/tool-src ; PATH=/root/tool-inst/bin:$PATH HOME=/root DISABLE_TASTE_BANNER=1 install/96_ZestSC1.sh'
RUN bash -c 'cd /root/tool-src ; PATH=/root/tool-inst/bin:$PATH HOME=/root DISABLE_TASTE_BANNER=1 install/97_upython.sh'
RUN bash -c 'cd /root/tool-src ; PATH=/root/tool-inst/bin:$PATH HOME=/root DISABLE_TASTE_BANNER=1 install/98_bash.sh'
RUN bash -c 'cd /root/tool-src ; PATH=/root/tool-inst/bin:$PATH HOME=/root DISABLE_TASTE_BANNER=1 install/99_paths.sh'

# Set up MSP430 toolchain
RUN apt -y install llvm-9
RUN bash -c 'cd /root/tool-src ; PATH=/root/tool-inst/bin:$PATH HOME=/root DISABLE_TASTE_BANNER=1 yes "y" | add-ons/install-msp430-gcc.sh'
RUN bash -c 'cd /root/tool-src ; PATH=/root/tool-inst/bin:$PATH HOME=/root DISABLE_TASTE_BANNER=1 yes "y" | add-ons/install-freertos.sh'
RUN bash -c 'cd /root/tool-src ; PATH=/root/tool-inst/bin:$PATH HOME=/root DISABLE_TASTE_BANNER=1 yes "y" | add-ons/install-adac-hybrid-msp430.sh'
RUN bash -c 'echo "export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/root/tool-inst/lib:/opt/adac-hybrid-msp430-1.0.1/lib" >> /root/.bashrc.taste'
# Patch MSP430 toolchain
RUN apt -y install libtinfo5
RUN bash -c 'ln -s /lib/x86_64-linux-gnu/libncursesw.so.6 /lib/x86_64-linux-gnu/libncursesw.so.5'

RUN bash -c 'echo ". ~/.bashrc.taste" >> /root/.bashrc'

# Deal with insane bugs in QT when redirecting X11 from a container
RUN bash -c 'echo "export QT_X11_NO_MITSHM=1" >> /root/.bashrc'
# And make sure the message queues of the container are large enough for TASTE GUIs
RUN bash -c 'echo "echo 100 > /proc/sys/fs/mqueue/msg_max" >> /root/.bashrc'
#
#
# At this point, you can start a fresh TASTE container with proper X11 redirection, with...
#
#     ./Docker-run.sh
#

