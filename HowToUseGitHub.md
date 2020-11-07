# 一、如何登录

## 1.创建SSH key

        本地Git仓库和Github仓库之间的传输是通过SSH加密传输的，GitHub需要识别，所以需要先生成公钥。

```csp
ssh-keygen -t rsa -C "注册GitHub的邮箱" 
```

## 2.在GitHub上配置公钥

        现在本地生成的公钥目录下，找到文件id_rsa.pub，然后复制其中的key至Github的设置中即可。

## 3.登录

```
ssh -T git@github.com
```

# 二、常用操作记录

## 1.查看当前的状态

```css
git status
```

## 2.初始化

对于一个空文件夹要先初始化

```
git init
```

## 3. 拉取远程分支到本地

```
git init
git remote add origin git@github.com:XXXX/xxx.git    //与origin matser建立链接
git fetch origin xx（xx为远程仓库的分支名）//把远程分支拉到本地
git checkout -b xx(本地分支名称) origin/xx(远程分支名称) //在本地创建分支dev并切换到该分支
git pull origin xx(远程分支名称)    //把某个分支上的内容都拉取到本地
```

## 4.删除关联的origin的远程库

```c
git remote rm origin
```

## 5.修改本地文件后，提交到远程仓库

```c
git status
```
