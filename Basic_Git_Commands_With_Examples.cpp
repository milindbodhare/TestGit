What is Git?
Git is a distributed version control system (DVCS). "Distributed" means that all developers within a team have a complete version of the project. A version control system is simply software that lets you effectively manage application versions. Thanks to Git, you'll be able to do the following:
a.Keep track of all files in a project
b.Record any changes to project files
c.Restore previous versions of files
d.Compare and analyze code
e.Merge code from different computers and different team members.


Configuring Git ::
When you come to a bank for the first time and ask to store your money there, they give you a bunch of paperwork to fill out. Before you can use banking services, you have to register with the bank. Git wants you to do the same (register with Git) before you start using a repository.
To tell Git who you are, run the following two commands:
$ git config --global user.name "King Kong"
$ git config --global user.email "king-kong@gmail.com"

Starting a New Local Repository with Git ::
To continue with our bank metaphor, we need to explicitly ask the bank to open a new safe deposit box to store our effects (read: code). Assuming you've already created an empty directory for your project, you need to explicitly ask Git to create a safe deposit box – a repository – in that directory:
$ git init
Initialized empty Git repository in /home/dell/new-folder/.git/

Git Branches ::
You can consider branches in Git as paths. Imagine that you explore a new territory and you mark the main path to water with poles each 10 to 15 meters. This main path is like the master branch, and the poles are like commits. We'll talk more about branches in the last section of the article. For now, it's sufficient to know that Git has a base branch called the master branch.

Git Commits ::
A commit to a repository is a snapshot of the current state of the project's root directory. Since this explanation doesn't really tell anything, we need to delineate the underlying concept.
Let's say you're working with a bunch of papers. You've written ten texts about animals on separate sheets of paper and you want to note what texts they are and when you wrote them. You take out another sheet of paper, call it a "commit," and write on this commit paper: "I've written text #1. It's about birds. I've written text #2. It's about dogs..." Then you create a copy of each text. The last thing you do is you gather those ten copies, pin the commit paper on top of them, and lay them in a drawer.
The next day you rewrite the original texts, then get the copies from your drawer and compare the texts. This is basically what Git does. You create files and write code in them. When you're ready, you commit your files to a repository: you create copies of files and lay them in a drawer (a repository). (Our inner nerd wants to specify that Git doesn't actually push copies of files to the repository; Git creates a light representation of the project files for performance benefits.)
Each day you write that commit message and add new texts. Git creates a history of your commits, so you can trace back to the very beginning of the project development to see what files have been changed or added, who added or changed them, and when.

Tracking Files with Git ::
Now we can answer the question, "Why does Git need to track files?" Before we commit any files to a local repository, Git wants to know what those files are. Git only knows what to commit when it's tracking files.
We've explained three basic Git concepts you need to know, but we've also moved far away from explaining Git commands. Nevertheless, it's crucial to grasp Git's basic concepts to understand how Git commands work. Now that we've explained the meaning of Git concepts, we can get back to the commands.
Let's remind you what output you'll see after you run "git status" for the first time:
$ git status
On branch master
Initial commit
nothing to commit (create/copy files and use "git add" to track)


Staging Files with Git ::
Before we cover simple Git commands used for staging files, we need to explain what the staging area is.
Let's say you want to move some of your valuable effects to a lock box, but you don't know yet what things you'll put there. For now, you just gather things into a basket. You can take things out of the basket if you decide that they aren't valuable enough to store in a lock box, and you can add things to the basket as you wish. With Git, this basket is the staging area. When you move files to the staging area in Git, you actually gather and prepare files for Git before committing them to the local repository.
To let Git track files for a commit, we need to run the following in the terminal:
$ git add my_new_file.txt
There's a problem with the "git add ." command. Since we're currently working in the root directory, "git add ." will only add files located in the root directory. But the root directory may contain many other directories with files. How can we add files from those other directories plus the files in the root directory to the staging area? Git offers the command below:
$ git add --all
Remember when we told you that you can take things out of your imaginary basket? Git can also take things out of its basket by removing files from the staging area. To remove files from the staging area, use the following command:
$ git rm --cached my-file.ts

Committing Changes to Git ::
Let's start with a quick overview of committing to the Git repository. By now, you should have at least one file tracked by Git (we have three). As we mentioned, tracked files aren't located in the repository yet. We have to commit them: we need to carry our basket with stuff to the lock box. There are several useful Git commands to do (almost) the same: move (commit) files from the staging area (an imaginary basket) to the repository (a lock box).
There's nothing difficult about committing to a repository. Just run the following command:
$ git commit -m "Add three files"
There will be times when you'll regret committing to a repository. Let's say you've modified ten files, but committed only nine. How can you add that remaining file to the last commit? And how can you modify a file if you've already committed it? There are two ways out. First, you can undo the commit:
$ git reset --soft HEAD^
Instead of resetting the HEAD and undoing the last commit, we can rectify a commit by using the "--amend" option when committing to a repository. Just add the remaining file to the staging area and then commit:
$ git add file-i-forgot-to-add.html
$ git commit --amend -m "Add the remaining file"


Push and Pull To and From a Remote Repository ::
a.In real development, your workflow will look like this:
b.You work on a feature and commit files to a branch (master or any other branch).
c.You push commits to a remote repository.
d.Other developers pull your commits to their computers to have the latest version of the project.
Now you need to bind this remote repository to your local repository:

$ git remote add origin https://github.com/YourUsername/some-small-app.git

copying your code to a remote repository looks like this:
$ git push -u origin master

Now that you've added a remote repository, you can view the list of repositories by running the following command:
$ git remote -v

So far we've talked about how to move your things to a remote lock box. Let's say your drawer with all your valuables has disappeared from your home. Now you want to get your things back from the lock box, kind of like cloning them. Git can clone an entire project from a remote repository. That's what the "clone" command does:
$ git clone git@github.com:YourUsername/your-app.git


List of Git Commands for Working with Branches ::
You'll use multiple branches for your projects. Branches are, arguably, the greatest feature of Git, and they're very helpful. Thanks to branches, you can actively work on different versions of you projects simultaneously.
Managing branches in Git is simple. Let's first see our current branches:
$ git branch

That's it: one command, "branch", will ask Git to list all branches. In our app, we have only one branch – master. But an application under development is far from being complete, and we need to develop new features. Let's say we want to add a user profile feature. To create this feature, we need to create a new branch:
$ git branch user-profile

For switching branches in Git, you won't use a "switch" command, as you might think. Instead, you'll need to use "checkout":
$ git checkout user-profile


You're stuck on the third step. What should you do next? The answer is simple: you need to use the "merge" command. To merge a secondary branch into the main branch (which can be a master, development, or feature branch), first switch back to the main branch. In our case, we should checkout the master branch:
$ git checkout master

The current branch is now changed to master, and we can merge the user-profile branch using the command "merge":
$ git merge user-profile


Let's mention a simpler command for creating new branches than "git branch <name>". Given that you're in the main branch and you need to create a new branch, you can just do this:
$ git branch my-new-branch
$ git checkout my-new-branch
