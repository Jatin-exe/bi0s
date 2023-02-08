# Over the Wire: Bandit-War Game

Here i include my Approach, Commands and what i learnt from playing Bandit war game of each level.



## Bandit 0
Basically ssh into the Bandit Server
```
ssh bandit.labs.overthewire.org -p 2220
``` 

## Bandit 0 -> 1
Copied the password from readme and logged into level 1
```
cat readme
ssh bandit.labs.overthewire.org -p 2220
```

## Bandit 1->2
Leant how to open files which have weird names
```
cat ~/"-"
``` 

## Bandit 2 -> 3
```
cat ./"spaces in this filename"
```
## Bandit 3 -> 4
```
ls -a
cd inhere
ls -a
cat .hidden
```

## Bandit 4 -> 5
Earlier i would have bruteforced all files but i tried using the `file` command here
```
cd inhere
file *
file ./*
cat ./-file07
```

## Bandi 5 -> 6
```
ls
cd inhere
ls
ls -al * | grep -B 10 1033
cat maybehere07/.file2
```

## Bandit 6 -> 7
```
ls
cd /
find ./ -group bandit6 -user bandit7 -size 33c
```
Password was in  `./var/lib/dpkg/info/bandit7.password`
```
cat ./var/lib/dpkg/info/bandit7.password
```
*got itt*

## Bandit 7 -> 8
```
cat data.txt | grep millionth
```
Done using piping


## Bandit 8 -> 9
```
ls
sort data.txt | uniq -u
```

## Bandit 9 -> 10
```
ls
cat data.txt | grep "="
strings data.txt
```


## Level 10 -> 11
```
ls
cat data.txt
```
Used [Base64decode.org](https://www.base64decode.org/ ) to decode `data.txt`

## Level 11 -> 12
```
ls
cat data.txt
```
Used [CyberChef](https://gchq.github.io/CyberChef/#recipe=ROT13(true,true,false,13)&input=R3VyIGNuZmZqYmVxIHZmIFdJQU9PU0Z6TWpYWEJDMEtvU0tCYko4cHVRbTVsSUVp) to decode the caeser cipher

### Bandit 12 -> 13 
In this the file is compressed using gzip bzip2 and tar several times,
we can find the compression type using file command and then uncompress accordingly
```
ls
cat data.txt
mkdir /tmp/newfile666
cp data.txt /tmp/newfile666
cd /tmp/newfile666
xxd -r data.txt data
file data
gzip -d dat
file data
mv data data.bz2
bzip2 -d data.bz2
file data
mv data data.gz
gzip -d data.gz
file data
tar -xf data
file data5.bin
tar -xf data5.bin
file data6.bin
bzip2 -d data6.bin
file data6.bin.out
tar -xf data6.bin.out
file data8.bin
mv data8.bin data8.gz
gzip -d data8.gz
file data8
cat data8
```

### Bandit 13 -> 14
Login to Bandit 14 using the private key in the home directory
```
ls
ssh -i sshkey.private bandit14@localhost -p 2220
```
**logged into bandit14**
```
cat /etc/bandit_pass/bandit14
```


## Bandit 14 -> 15
Submit the password of Bandit 14 to port 30000 using nc command
```
echo "fGrHPx402xGC7U7rXKDaxiWFTOiF0ENq" | nc localhost 30000

```

## Bandit 15 -> 16
Submit current password on port  30001 of localhost using SSL encryption
```
echo "jN2kgmIXJ6fShzhT2avhotn4Zcka6tnt" | openssl s_client -connect localhost:30001

```

## Bandit 16 -> 17
```
nmap localhost -p 31000-32000 -sV --version-i
31518, 31790 had ssl ports
echo "JQttfApK4SeyHwDlI9SXGR50qclOAil1" | nc localhost 31790
```
**echoed this RSA key**
```
-----BEGIN RSA PRIVATE KEY-----
MIIEogIBAAKCAQEAvmOkuifmMg6HL2YPIOjon6iWfbp7c3jx34YkYWqUH57SUdyJ
imZzeyGC0gtZPGujUSxiJSWI/oTqexh+cAMTSMlOJf7+BrJObArnxd9Y7YT2bRPQ
Ja6Lzb558YW3FZl87ORiO+rW4LCDCNd2lUvLE/GL2GWyuKN0K5iCd5TbtJzEkQTu
DSt2mcNn4rhAL+JFr56o4T6z8WWAW18BR6yGrMq7Q/kALHYW3OekePQAzL0VUYbW
JGTi65CxbCnzc/w4+mqQyvmzpWtMAzJTzAzQxNbkR2MBGySxDLrjg0LWN6sK7wNX
x0YVztz/zbIkPjfkU1jHS+9EbVNj+D1XFOJuaQIDAQABAoIBABagpxpM1aoLWfvD
KHcj10nqcoBc4oE11aFYQwik7xfW+24pRNuDE6SFthOar69jp5RlLwD1NhPx3iBl
J9nOM8OJ0VToum43UOS8YxF8WwhXriYGnc1sskbwpXOUDc9uX4+UESzH22P29ovd
d8WErY0gPxun8pbJLmxkAtWNhpMvfe0050vk9TL5wqbu9AlbssgTcCXkMQnPw9nC
YNN6DDP2lbcBrvgT9YCNL6C+ZKufD52yOQ9qOkwFTEQpjtF4uNtJom+asvlpmS8A
vLY9r60wYSvmZhNqBUrj7lyCtXMIu1kkd4w7F77k+DjHoAXyxcUp1DGL51sOmama
+TOWWgECgYEA8JtPxP0GRJ+IQkX262jM3dEIkza8ky5moIwUqYdsx0NxHgRRhORT
8c8hAuRBb2G82so8vUHk/fur85OEfc9TncnCY2crpoqsghifKLxrLgtT+qDpfZnx
SatLdt8GfQ85yA7hnWWJ2MxF3NaeSDm75Lsm+tBbAiyc9P2jGRNtMSkCgYEAypHd
HCctNi/FwjulhttFx/rHYKhLidZDFYeiE/v45bN4yFm8x7R/b0iE7KaszX+Exdvt
SghaTdcG0Knyw1bpJVyusavPzpaJMjdJ6tcFhVAbAjm7enCIvGCSx+X3l5SiWg0A
R57hJglezIiVjv3aGwHwvlZvtszK6zV6oXFAu0ECgYAbjo46T4hyP5tJi93V5HDi
Ttiek7xRVxUl+iU7rWkGAXFpMLFteQEsRr7PJ/lemmEY5eTDAFMLy9FL2m9oQWCg
R8VdwSk8r9FGLS+9aKcV5PI/WEKlwgXinB3OhYimtiG2Cg5JCqIZFHxD6MjEGOiu
L8ktHMPvodBwNsSBULpG0QKBgBAplTfC1HOnWiMGOU3KPwYWt0O6CdTkmJOmL8Ni
blh9elyZ9FsGxsgtRBXRsqXuz7wtsQAgLHxbdLq/ZJQ7YfzOKU4ZxEnabvXnvWkU
YOdjHdSOoKvDQNWu6ucyLRAWFuISeXw9a/9p7ftpxm0TSgyvmfLF2MIAEwyzRqaM
77pBAoGAMmjmIJdjp+Ez8duyn3ieo36yrttF5NSsJLAbxFpdlc1gvtGCWW+9Cq0b
dxviW8+TFVEBl1O4f7HVm6EpTscdDxU+bCXWkfjuRb7Dy9GOtt9JPsX8MBTakzh3
vBgsyi/sN3RqRBcGU40fOoZyfAMT8s1m/uYv52O6IgeuZ/ujbjY=
-----END RSA PRIVATE KEY-----
```
**saved this key in /tmp/jatin123/key**
```
cd /tmp
chmod 600 bandit17password.key
ssh -i bandit17password.key bandit17@localhost -p 2220
```


## Bandit 17 -> 18
```
diff passwords.new passwords.old
```
*ez pzy lemon squezy*

## Bandit 18 -> 19
```
saw "Byebye !"
ssh bandit18@bandit.labs.overthewire.org -p 2220 "cat readme"
```


## Bandit 19 -> 20
Learnt about setuid, where users can execute files with elevated perms
```
./bandit20-do
./bandit20-do cat /etc/bandit_pass/bandit20
```
So basically when i execute `./bandit20-do` as bandit19  i get perms of bandit 20 using which i can see the password of bandit 20

## Bandit 20 -> 21
Open two terminals
```
nc -l 5000  < /etc/bandit_pass/bandit20
```
Got password in other terminal

## Bandit 21 -> 22
```
cd /etc/cron.d
cat cronjob_bandit22
cat /usr/bin/cronjob_bandit22.sh
cat /tmp/t7O6lds9S0RqQh9aMcz6ShpAoZKF7fgv
```
We are seeing what the script does and trying to retrieve the password
Reverse Engineering 101!!
*ez peazy*

## Level 22 -> 23
```
cd /etc/cron.d
cat cronjob_bandit23
cat /usr/bin/cronjob_bandit23.sh
$(echo I am user bandit22 | md5sum | cut -d ' ' -f 1)
cat /tmp/8ca319486bfbbc3663ea0fbe81326349
```
Same as above mostly

## Level 23 -> 24
```
cd /etc/cron.d
cat cronjob_bandit24
cat /usr/bin/cronjob_bandit24.sh
vim /tmp/jk/pass.sh
```

> cat /etc/bandit_pass/bandit24 > /tmp/s8n.txt

```
chmod 777 /tmp/jk/pass.sh
touch /tmp/jk/jk.txt
chmod 666 /tmp/jk/jk.txt
cp /tmp/jk/pass.sh /var/spool/bandit24/foo
```
*hold on*
```
cat /tmp/jk/jk.txt
```


## Bandit 24 -> 25
```
nano /tmp/pswd.sh
```

>  #!/bin/bash
>
 >for i in {1000..9999}
>do	       
>			echo "VAfGXJ1PBSsPSnvsjI8p759leLZ9GGar $i"
>done
```
./pswd.sh | nc  localhost 30002
```


## Bandit 25 -> 26 -> 27
Minimize your termianl then use `more` command on text.txt
```
cat /etc/passwd | grep bandit26
cat /usr/bin/showtext
```

```
ssh -i bandit26.sshkey bandit26@bandit.labs.overthewire.org -p 2220
v
:e /etc/bandit_pass/bandit26
```
*enter the shell of bandit26*

```
:set shell=/bin/bash
:shell
./bandit27-do cat /etc/bandit_pass/bandit27
```


## Bandit 27 -> 28
```
git clone ssh://bandit27-git@localhost:2220/home/bandit27-git/repo
cd repo
cat README
```

## Banidt 28 -> 29
```
mktemp -d
cd <folder>
git clone ssh://bandit28-git@localhost:2220/home/bandit28-git/repo
cd repo
cat README.md
git log -p
```


## Bandit 29 -> 30
```
mktemp -d
cd <folder>
git clone ssh://bandit29-git@localhost:2220/home/bandit29-git/repo
cd repo
cat README.md
git log -p
git branch -a
git checkout origin/dev
cat README.md
```


## Bandit 30 -> 31
```
mktemp -d
cd <folder>
git clone ssh://bandit30-git@localhost:2220/home/bandit30-git/repo
cd repo
cat README.md
git log -p
git branch -a
git tag
git show secret
```


## Bandit 31 -> 32
```
mktemp -d
cd <folder>
git clone ssh://bandit31-git@localhost:2220/home/bandit31-git/repo
cd repo
cat README.md
vim key.txt
ls -a
rm .gitignore
git add key.txt
git commit -m "ok?"
git push origin master
```


## Bandit 32 -> 33
```
$0
ls -alt
whoami
cat /etc/bandit_pass/bandit33
```
Done all Done









