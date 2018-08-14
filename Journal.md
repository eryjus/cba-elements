***CBA-Elements***

This file contains a running journal of my development exerience and documents some of the decisions I have made during this life-cycle.  This is partly for me and partly for anyone else to be able to review all my experiences and potentially learn from this.

I am relatively new at the whole MVC design concept, so this should be fun!

---

**2018-07-26**

Before I started this file, I was able to get a basic MySQL database file to compile called `db.cc`, which is defined in `db.h`.  The key here is that the file compiles.

There are also some design decisions in this file that I may regret.  For example, there is only one connection object, which may be a problem if I have databases spread across multiple servers.  For now, my intent is to keep these all on the same database instance.  Another thing I may regret and change is the the connection information is all kept in global static variables.  Eventually, this will likely all be encapsuated into its own class.

So, it is important to understand these 2 files become the basis for all models, at least from a data perspective.  These will be used to get, process, and store data to the persistent database.

The first model I need to start with will be the `cba_metadata.elements` table.  There will need to be functions to insert a new element, update an existing element, fetch an existing element, check for existence of an existing element, and get a list of elements matching the search criteria.

So, here is the plan:
* Create a class `ModelElements`
* Create factory, constructor, and destructor methods
* Create a method `CheckTableExists()`
* Create a method `CreatTable()`
* Create a method `ClearCurrentRecord()`
* Create a method `InsertRecord()`
* Create a method `UpdateRecord()`
* Create a method `DeleteRecord()`
* Create a method `FetchRecord()`
* Create a method `SelectRecords()`
* Create all the different access methods for each column

A single class instance will have the ability to control a single record.  The SelectRecords() function will return a record set from SQL, which can then be used to whittle down to a single record.

Now, it makes sense to me to create an abstract class for any model class we will use and then inherit from that class.  In order to do this, I will need to create several helper classes (such as a key class of some sorts) rather than passing in a dynamic list of parameters for each different type of fetch that can be performed.

So the question is what to do first....  Do I create the functions as concrete methods and create several versions of the methods for each use case I might have (and then go back and re-create them when it is time to change)?  Or, do I bite the bullet now and create all the helper classes now as I identify them.  For the former, I will have a lot of rework to do while I get the benefit of rapid development.  In the latter, I get things done right the first time but it will take some time before I can execute some meaningful code.  For this project, I think I would prefer doing it right the first time.  So, that is the approach.

As a result, there will be dual development between the `ModelElements` class and an abstract `Model` class.

---

**2018-07-27**

Today I have several functions I have implemented.  However, there are still exceptions that I need to handle.  The `try ... catch` clauses need to be added to make the code complete.  However, I am not yet sure if I am going to throw additional exceptions or set an error value that can be retrieved...  yet.

I did hide the update and delete record functions for the moment because additional constructs will need to be added in order to complete these functions.

I have also added a `GetCurrentDateTime()` function to get the current date and time in a string format that can be used to update the record audit trail.

I was able to perform some basic debugging and confirm that I am creating the schema properly when I run the program.  This is a good milestone, as it proves that I am communicating with the database and interacting with it properly without throwing any errors.

I still have several access methods to create, so I will work on those.  I am working at work this evening on an OS upgrade to an IBM iSeries system, so there is a lot of waiting for processes to complete.  This is good stuff to work on to keep me busy while I wait for the system.

---

**2018-07-28**

Today I started looking at a logging facility to include in the code.  I found this article (http://www.drdobbs.com/cpp/a-lightweight-logger-for-c/240147505?pgno=1) which appears to fit the bill nicely, but is rather diffucult to assemble properly.  It will have to be reverse engineered a bit to be able to understand how to put it back together again.

I was able to recode the logger to my own personal standards, and I like the results a little better.  My verion of the source from the logger from the web site are found in `logger.h` and `logger.cc`.

---

**2018-07-29**

This morning, I finished up the initial population of the elements table with data for the elements table.  This seems circular, but each field in the elements table is actually an element that needs to be tracked in that same table.  The program will now insert this data automatically when the table is created to per-populate the fields for future use.

So, now I need to figure out if I am going to track this with git and place it on github....  I believe that git tracking is a no-brainer.  It has to happen, and now is as good a time as any to get started.  As for githib, I am debating that one.  For the moment, this is just play to learn how to interoperate on C9, learn how to integrate with MySQL with C++, and learn how to develop a GUI application for Linux.  But then again, others may benefit from my progress here (which is partly why I keep this file!).  So, I guess github it is.

---

**2018-08-03**

Well, I obviuosly have been busy for a few days.  I have been travelling for work and there were some issues that took quite a bit of my time and effort, and by the time I was back in the hotel room, I had no energy left.

So, where did I leave off and what to do next...?

That's right: I have been researching and working on getting a qt5 application working.

This utility appears to have worked the best. I am able to get a vnc session started:  https://github.com/billyprice1/cloud9-vnc

So, now I need to create a trivial GUI application for testing.

---

**2018-08-05**

I have what I think is a working application written.  I have noVNC installed and working for the Cloud9 system.  Now all I have to do is to able to test it successfully and make sure I can run my applicaiton over noVNC.

I had to do some additional work to ensure that things were working properly.  This is found on this post: https://community.c9.io/t/how-to-set-display-in-my-workspace/1646/22.

I was finally able to get a basic application to run and view the results.  The code to accomplish this basic test is the following:

```c++
    QApplication app(argc, argv);
    QPushButton button ("Hello world !");
    button.show();
    app.exec();
```

To complete this test, I was required to comment out the MySQL code, so they are not coexisting at the moment.  I need to resolve that as well.  This turned out to be just as simple as starting the MySQL server.

---

Having committed this code, I now need to lay out this applicaiton and build out the UI.  Since I am not familiar with Qt, this may take some time and some research.

OK, so I have found the class reference on the web for Qt.  It is found here: http://doc.qt.io/archives/qt-4.8/classes.html.

With this, I believe I have all I need to start constructing the application framework.  The key here for me is going to be keeping the view separated from the controller.

I was able to get an application window and a menu set up.  The menu options do not do anything at the moment.

I think this is a good point to commit the code again today.

---

So, I think the next thing to work on is the About dialog box.  It seems simple enough to incorporate as I learn and appropriate enough to do first.  To accomplish this, I will need to doctor up the menu option to work, create and display the dialog box, self-destroy the dialog box, and tie the menu option to the actual dialog to display.

Finally, a quick observation: it appears that Qt and JavaFX are architected quite similarly.  Some thing might be able to translate 1:1 and Qt might be able to be a build target for CBA as well as JavaFX.

---

**2018-08-06**

So, I am coding from a plane today.  To say things are tight is a bit of an understatement.

I am going to work on developing the About dialog box and hooking that to the proper menu item.  Well, as much as I can anyway.

OK, I'm have an about dialog painting and I am trying to understand how to tie the menu to the dialog.  I know tjis will need to be done with a QAction object or subclass, but I also am trying to figure out how to deal with signals and slots.  I am reviewing this site: http://doc.qt.io/archives/qt-4.8/signalsandslots.html.

---

**2018-08-08**

I'm trying to figure out where I left off.  I think I have most of this pulled together from the plane ride.  Not totally sure though.  So I think I am going to have to compile and run and try to figure out what I have in place....

So, it looks like I have nearly everything coded.  The only thing left that I can see is to create a reference to the About dialog and add it into the connect() function call.

So, as I am trying to pull this last connection together, I am struck thinking about how I really need to pull this together.  I think I want my Controllers to be responsible for creating the View and Models for which is coordinates.  At the same time, the main window controller will build and maintain the controllers for each element it will communicate with.

This means I have some restructuring to do of the build system and of the code.

So, let's start with the main window.  The main window has a View and a Controller, but there is no need for a Model since there is no data to manage/manipulate.  However, this Controller also need to be responsible for creating all the other Controllers that will be used.

Now for file organization...  I think I want to split the files into `model`, `view`, `ctlr` folders for both the `src` and `inc` folders.  This will leave a few specific files in the root, which can be moved into a `util` folder.  Then the `#include`s will be folder specific.  Now, this leaves a problem with the sources and the resulting `Makefile` recipes....  This part may be a bit of a mess.

Now that I have the system organized and the code building again (at least to the same point it was before I started making changes), I need to make sure I build out the main window controller.

---

**2018-08-09**

I started working on the main window controller today.  And then I realized that I will actually need a model for the main application.  The reason for this is that the main window controller will open the database connection and close it on exit.  This follows the Model implementation.

At the same time as I work on the above, I am also working on renames again since I am not pleased with the current source file naming (which has not been committed, so you will not see it).

OK, as I have been able to compile this again, I am moving back away from the folders.  The problem for me was that `make` was not able to properly keep track of what really needed to be built, so it was forcing full builds with every compile.  I have enough going on that it takes a while to compile so reducing the number of files to rebuild was a relevant time saver.  I really wish I could get `tup` working on Cloud9.

---

OK, I was able to figure out how to get `tup` running, so I will be refactoring the `Makefile` to use tup to execute the build.  `make` will still be used, but at its heart, `tup` will execute the build.  I expect that this will dramatically improve the build time and accuracy, so there will no need to have the `make clean` and `make force` build targets.  Well....  maybe.

---

**2018-08-10**

Well, I am still struggling with getting `tup` to work.  Actually, `tup` is built, but I cannot get fuse to work.  So, it's back to the `Makefile`.

Running the code, does not launch the window.  So, I have some debugging to do....  Done.

---

**2018-08-11**

OK, so the task for today is to figure out how to connect the main window controller to the about dialog controller so that the menu option causes the about dialog to be displayed.  I will need to look around for some examples, but I'm sure it will involve signals and slots.

This Qt page appears to have all the necessary information I need to implement the menu actions.  I will use that as a template to fill in the necessary functions on the MainWindowController class.

Well, with nearly everything coded and compiling, I am discovering that there are some issues with writing a good connect() function call.  I am getting error messages issued on the screen that I am struggling to resolve properly.

So, with some research, I figured out that I needed to add the Q_OBJECT macro at the top of the class definition.  Then I am getting an undefined vtable for the object I added the macro to...  so this is where the `moc` step comes in...  it will create all the missing virtual methods.  So I have to add this to the build to generate this file.

I have been able to resolve this down to a segmentation fault -- which means a likely null pointer dereference.

---

**2018-08-13**

Today's task was to update everything to use Qt5.  With that, I was able to get the About dialog to display.

---

**2018-08-14**

I was able to get the About dialog to remain modal and stay on top of the application.  This actually gives me a pretty good running application that I am going to commit.  However....  before I do that, do I want to make some effort to combine the header files and create some abstract classes for the View and Controller (since I already have one for Model)?

Well, this is the risk of trying to learn something all on my own and without having something concrete to use as an example.  I have this all wrong and nearly all my code so far needs to be dumped.  I found this: http://doc.qt.io/qt-5/modelview.html.  So, I am going to commit this code now for 2 reasons: 1) so I have something I can refer back to, and 2) so you have something you can look at before I make all these sweeping changes again.  I have no idea what it is going to look like when I get done, but it will not look like what I am about to commit!


