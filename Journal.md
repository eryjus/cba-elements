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



