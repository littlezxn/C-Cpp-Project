#!/usr/bin/env bash
set -euo pipefail

if [ "${EUID:-$(id -u)}" -ne 0 ]; then
  SUDO="sudo"
else
  SUDO=""
fi

if [ -f /etc/os-release ]; then
  # shellcheck disable=SC1091
  . /etc/os-release
  DIST_ID="${ID:-}"
  DIST_LIKE="${ID_LIKE:-}"
else
  DIST_ID=""
  DIST_LIKE=""
fi

install_debian_like() {
  $SUDO apt-get update
  $SUDO apt-get install -y build-essential gcc g++ gdb make cmake pkg-config
}

install_rhel_like() {
  if command -v dnf >/dev/null 2>&1; then
    $SUDO dnf install -y @development-tools gcc gcc-c++ gdb make cmake pkgconf-pkg-config
  elif command -v yum >/dev/null 2>&1; then
    $SUDO yum groupinstall -y "Development Tools"
    $SUDO yum install -y gcc gcc-c++ gdb make cmake pkgconfig
  else
    echo "No dnf or yum found."
    exit 1
  fi
}

install_arch_like() {
  $SUDO pacman -Syu --noconfirm base-devel gcc gdb make cmake pkgconf
}

install_suse_like() {
  $SUDO zypper refresh
  $SUDO zypper install -y gcc gcc-c++ gdb make cmake pkg-config
}

case "$DIST_ID" in
  ubuntu|debian|linuxmint|pop|elementary|kali|raspbian)
    install_debian_like
    ;;
  fedora|rhel|centos|rocky|almalinux)
    install_rhel_like
    ;;
  arch|manjaro|endeavouros)
    install_arch_like
    ;;
  opensuse*|suse)
    install_suse_like
    ;;
  *)
    case "$DIST_LIKE" in
      *debian*)
        install_debian_like
        ;;
      *rhel*|*fedora*|*centos*)
        install_rhel_like
        ;;
      *arch*)
        install_arch_like
        ;;
      *suse*)
        install_suse_like
        ;;
      *)
        echo "Unsupported distro: ID='$DIST_ID' ID_LIKE='$DIST_LIKE'"
        exit 1
        ;;
    esac
    ;;
esac

echo "C/C++ essentials installed."
