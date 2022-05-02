
#include <stdio.h>
#include <string.h>
#include "twitter_create.h"

void create_twitter_system(twitter * twitter_system)
{
    //to create 100 blank users with there user name taken from the standard input

    user users[MAX_USERS];
    tweet newsFeed[MAX_TWEETS];
    int number_of_tweets = 0;

    //loop to create the users
    int i;
    for(i = 0; i < MAX_USERS; i++)
    {
        printf("Input the username of the next OR Press <Enter> to terminate:\n");
        fgets(users[i].username, USR_LENGHT, stdin);

        //code to take a backslash n from the string

        if(users[i].username[strlen(users[i].username)-1] == '\n')
        {
            users[i].username[strlen(users[i].username)-1] = '\0';
        }

        //condition for if the user presses enter

        if(strcasecmp("", users[i].username) == 0)
        {
            return;
        }

        //put the user in the actual twitter structure under users

        strcpy(twitter_system->users[i].username, users[i].username);

        //increment the amount of actual users

        twitter_system->num_users++;


        //initialise also the followers to 0 and the number of following to 0 too

        twitter_system->users[i].num_followers = 0;
        twitter_system->users[i].num_following = 0;
    }
}
//this function should take 2 users a and b then make a follow b

void follow(user * a, user * b)
{
    //condition as to whether a and b are the same user
    if(strcasecmp(a->username, b->username) == 0)
    {
        printf("A user cannot follow themselves\n");
        return;
    }

    //copy b's username into the array that a is following
    strcpy(a->following[a->num_following], b->username);

    //increment the number a is following by 1
    a->num_following++;

    //update b to have a as a follower
    //put a's name in b's followers list

    strcpy(b->followers[b->num_followers], a->username);

    //increment the number of followers b has by one
    b->num_followers++;
}

//this function should take two users a and b and make a unfollow b

void unfollow(user * a, user * b)
{
    //condition as to whether a and b are the same user
    if(strcasecmp(a->username, b->username) == 0)
    {
        printf("A user cannot unfollow themselves\n");
        return;
    }

    //remove b's username from the array that a is following
    //....
    int i;

    for(i = 0; i < a->num_following; i++)
    {
        if(strcasecmp(a->following[i], b->username) == 0)
        {
            //code to remove b's username...
            while(i < a->num_following - 1)
            {
                strcpy(a->following[i], a->following[i+1]);
                i++;
            }
            break;
        }
        else
        {
            continue;
        }
    }

    //decrement the number a is following by 1
    a->num_following--;

    //update b to not have a as a follower
    //remove a's name from b's followers list
    //...

    for(i = 0; i < b->num_followers; i++)
    {
        if(strcasecmp(a->followers[i], a->username) == 0)
        {
            //code to remove a's username...
            while(i < b->num_followers - 1)
            {
                strcpy(b->followers[i], b->followers[i+1]);
                i++;
            }
            break;
        }
        else
        {
            continue;
        }
    }

    //decrement the number of followers b has by one
    b->num_followers--;
}
