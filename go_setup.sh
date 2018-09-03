spacemacs_go_prereqs() {
    go get -u -v github.com/nsf/gocode
    go get -u -v github.com/rogpeppe/godef
    go get -u -v golang.org/x/tools/cmd/oracle
    go get -u -v golang.org/x/tools/cmd/gorename
    go get -u -v golang.org/x/tools/cmd/goimports
    go get -u -v github.com/alecthomas/gometalinter
    gometalinter --install --update
}

go_dowload_install(){
    export GO_VERSION
    GO_VERSION=$(curl -sSL "https://golang.org/VERSION?m=text")
    export GO_SRC=/usr/local/go
    
    # if we are passing the version
    if [[ ! -z "$1" ]]; then
        GO_VERSION=$1
    fi
    
    shell_profile=bash_profile
    touch "$HOME/.${shell_profile}"
    {
        echo '# GoLang'
        echo 'export GOROOT=/usr/local/go'
        echo 'export PATH=$PATH:$GOROOT/bin'
        echo 'export GOPATH=$HOME/go'
        echo 'export PATH=$PATH:$GOPATH/bin'
    } >> "$HOME/.${shell_profile}"
    
    . .bashrc
    
    GO_VERSION=${GO_VERSION#go}
    
    # subshell
    (
        kernel=$(uname -s | tr '[:upper:]' '[:lower:]')
        curl -sSL "https://storage.googleapis.com/golang/go${GO_VERSION}.${kernel}-amd64.tar.gz" | sudo tar -v -C /usr/local -xz
        local user="$USER"
        # rebuild stdlib for faster builds
        sudo chown -R `whoami` /usr/local/go/pkg
        CGO_ENABLED=0 go install -a -installsuffix cgo std
    )
}


go_packages(){
    # get commandline tools
    (
        set -x
        set +e
        go get github.com/golang/lint/golint
        go get golang.org/x/tools/cmd/cover
        go get golang.org/x/review/git-codereview
        go get golang.org/x/tools/cmd/goimports
        go get golang.org/x/tools/cmd/gorename
        go get golang.org/x/tools/cmd/guru
        
        go get github.com/genuinetools/amicontained
        go get github.com/genuinetools/apk-file
        go get github.com/genuinetools/audit
        go get github.com/genuinetools/certok
        go get github.com/genuinetools/netns
        go get github.com/genuinetools/pepper
        go get github.com/genuinetools/reg
        go get github.com/genuinetools/udict
        go get github.com/genuinetools/weather
        
        go get github.com/jessfraz/junk/sembump
        go get github.com/jessfraz/secping
        go get github.com/jessfraz/ship
        go get github.com/jessfraz/tdash
        
        go get github.com/axw/gocov/gocov
        go get honnef.co/go/tools/cmd/staticcheck
        
        # Tools for vimgo.
        go get github.com/jstemmer/gotags
        go get github.com/nsf/gocode
        go get github.com/rogpeppe/godef

        #gotest 
        go get -u github.com/cweill/gotests/...
    )
    
}

go_dowload_install
spacemacs_go_prereqs

# if go version is 1.10 then use https://github.com/mdempsky/gocode

