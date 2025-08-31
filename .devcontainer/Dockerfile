FROM ubuntu:24.04
LABEL author="Austin Tabulog"

# tell OS not to prompt user for installation data
ENV DEBIAN_FRONTEND=noninteractive

#update package managers and allow https and common repos
RUN apt update && apt upgrade -y
RUN apt-get update && apt-get upgrade -y
RUN apt install -y \ 
    apt-transport-https \
    software-properties-common

# Install build essentials and C/C++ tools
RUN apt-get install -y \
    bash \
    build-essential \
    clang \
    clang-format \
    clang-tidy \
    cmake \
    curl \
    dos2unix \
    doxygen \
    gdb \
    git \
    libgtest-dev \
    libgmock-dev \
    lcov \
    libconfig-dev \
    nano \
    python3 \
    python3-pip \
    python3-venv \
    tar \
    tzdata \
    unzip \
    wget

#build google test and mock from source and install
RUN cd /usr/src/googletest && cmake . && make && cp ./lib/*.a /usr/lib

#set timezone
RUN ln -fs /usr/share/zoneinfo/America/Chicago /etc/localtime
RUN  echo "America/Chicago" | tee /etc/timezone

# set text encodings
RUN apt install locales && locale-gen en_US.UTF-8


#turn on terminal defaults and allow color
ENV TERM=xterm-256color
SHELL ["/bin/bash", "-c"]

#set python symlink
RUN ln -s /usr/bin/python3.12 /usr/bin/python

# Set working directory
WORKDIR /workspace

# set bashrc settings 
RUN echo '# Custom interactive shell enhancements' >> ~/.bashrc && \
    echo 'export TERM=xterm-256color' >> ~/.bashrc && \
    echo 'alias ll="ls -alF"' >> ~/.bashrc && \
    echo 'alias la="ls -A"' >> ~/.bashrc && \
    echo 'alias l="ls -CF"' >> ~/.bashrc && \
    echo 'export PS1="\[\e[32m\]\u@\h:\[\e[34m\]\w\[\e[0m\]\$ "' >> ~/.bashrc && \
    echo 'if [ -f /etc/bash_completion ]; then . /etc/bash_completion; fi' >> ~/.bashrc

# add git completion support
RUN curl -o /root/.git-completion.bash https://raw.githubusercontent.com/git/git/master/contrib/completion/git-completion.bash && \
    echo "source /root/.git-completion.bash" >> /root/.bashrc

# add CLI formatting support for git
RUN curl -o /root/.git-prompt.sh https://raw.githubusercontent.com/git/git/master/contrib/completion/git-prompt.sh && \
    echo "source /root/.git-prompt.sh" >> /root/.bashrc && \
    echo "export PS1=\\[\\033[01;32m\\]\\u@\\h\\[\\033[00m\\]:\\[\\033[01;34m\\]\\w\\[\\033[31m\\]\$(__git_ps1 \" (%s)\")\\[\\033[00m\\]\\$ '" >> /root/.bashrc

CMD ["/bin/bash"]