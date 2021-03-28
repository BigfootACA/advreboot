# Maintainer: BigfootACA<bigfoot@classfun.cn>

pkgname=advreboot
pkgver=1.0
pkgrel=1
pkgdesc="Advanced reboot caller"
arch=(x86_64 i686 aarch64 armv6 armv7)
url="https://github.com/BigfootACA/advreboot"
license=(LGPL3)
depends=(glibc)
source=(
	advreboot.c
	LICENSE
	Makefile
)

build(){
	make
}

package(){
	make DESTDIR="$pkgdir/" install
	install -Dm644 LICENSE -t "$pkgdir/usr/share/license/$pkgname"
}
md5sums=('51376eb7a5eadd772cfa84cc0eb1cf40'
         '3000208d539ec061b899bce1d9ce9404'
         '6eecd8d77ac3f18f8c5c262a869c0f5d')
