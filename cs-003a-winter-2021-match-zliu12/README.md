# Match

Your company has decided to diversify into matchmaking. As a first step, it is offering a service to pair people for a first date and asked you to write the software for the pairing. Initial requirements are relatively simple:

* Pairing will be between males and females only for now.
* Each profile will specify the user's **id** along with attributes **country**, **diet**, **drinking**, **gender**, **language**, **religion**, and **smoking**.
* The company expects each user to prefer to be paired with users sharing the attributes. E.g., a user from USA will want to be paired with another also from USA.
* The importance a user gives to a match on an attribute is indicated in an accompanied weight value. E.g., for country, you may get a tuple (USA, 0.340077), which specifies that the user is from USA and that the match is worth 0.340077 to him/her.
* The company calculates a compatibility score for each pair by combining the user weights for each matching attribute. E,g, if user A matches with B on country and they assign weights 0.3 and 0.4 respectively for it, they will contribute a value of 0.7 to the score (and 0 if they don't match).

Your job is to pair each male with a female for their first date so the pairs represent the most compatible matching across all the users. The logic is to be placed in **Match::pairs()** in **match/match.cpp**, and you need to write **unit tests** for it in **test/match_test.cpp**.

In addition to the unit tests, you will also be creating an **integration test** in **report.cpp** to check out the full flow. This will pair 100 users (50 males with 50 females) using your match logic above and generate a report pairing each male's **id** (first column) with the matching female's **id**, along with the compatibility score. Sort these in the alphabetical order of the male **id**.

The *data* package provides a **profiles()** function that you can use to get a list of randomly generated profiles - you are guaranteed to get half males and half females. However, **do not make any assumptions about the order** (e.g., they may not strictly alternate in gender).

Use the below **bazel** commands to test:

1. **bazel test test/match_test** to run your unit tests
2. **bazel run report** to run your integration test