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

# 二、常用基础操作

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

## 5.修改（添加、删除）本地文件后，提交到远程仓库

（0）最开始查看状态，会显示“Changes not staged for commit”，即变化未筹划提交。

（1）将文件提交“add”,Git会把“add”的文件标记为"Ready for commit"（准备提交）的状态。相当于把文件标记为“staged for commit”（筹划提交）。git status会显示为“Changes to be committed”（变化将被提交）。

（2）“commit”已经“add”的文件。

（3）将文件上传到你的 GitHub 仓库。

```c
git status                //查看当前状态
git add xxxx(文件名)       //添加
git commit -m "xxx"       //xxx相当于对添加的文件的注释
git push -u origin master //提交到远程仓库
```

## 6.clone远程仓库至本地

```c
git clone git@github.com:XXXX/xxx.git
```

## 7.查看文件变化

```c
git diff
```

    需要注意的是，如果当运行了git add后，git diff不会输出任何东西，因为已经添加了文件。所以执行下面的语句：

```c
git diff --cached
```

    它会告诉 Git 添加的当前版本和以前版本文件之间的差别。

## 8.add的用法

```c
git add xxx
```

（1）添加一个文件

（2）跟踪一个没有被Git跟踪的文件

# 三、常用分支操作

### 有了分支，可以让可以正常运行的分支不会受正在开发的人的影响，正在开发的人开辟新的分支进行开发，如果是多人合作，项目的所有者可以根据不同人的贡献，选择分支中的有用的部分进行合并。

## 1.列出该项目在主机上的全部分支

```c
git branch
```

## 2.git status状态讲解

```c
Your branch is up to date with 'origin/master'.
```

意义就是它与 `origin/master` 处于同步状态，这意味着master 分支的本地副本中的全部文件也出现在 GitHub 中。两份副本没有差异，所有的提交也是一致的。

## 3.创建一个新分支

```c
git checkout -b myBranch
```

`-b` 告知 Git 创建一个名为 `myBranch` 的新分支，然后 `checkout` 命令将我们切换到新创建的分支。

## 4.可视化查看分支

```c
gitk
```

## 5.删除分支

```c
git branch -D xxx
```

## 6.删除远程分支

```c
git push origin :myBranch
```

注意：一定要注意origin后的空格！









# 参考

1.https://linux.cn/article-9517-3.html
