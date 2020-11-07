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

## 2.
