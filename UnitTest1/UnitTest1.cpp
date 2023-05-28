#include "pch.h"
#include "CppUnitTest.h"
#include "customer_test.h" // Include the C code file containing getCustomerInfo
#include "iostream"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CustomerInfoTestSuite
{
    TEST_CLASS(CustomerInfoTest)
    {
    public:
        TEST_METHOD(GetCustomerInfoTest)
        {
            // Redirect input stream to provide test input
            std::stringstream input;
            input << "Deen" << std::endl;             // First name
            input << "Adenowo" << std::endl;            // Last name
            input << "2800 Keele str." << std::endl;       // Street address
            input << "Toronto" << std::endl;          // City
            input << "ON" << std::endl;               // Province
            input << "M3M 0B8 " << std::endl;          // Postal code

            std::streambuf* prevCin = std::cin.rdbuf(input.rdbuf());

            // Call the getCustomerInfo function
            struct Customer customer = getCustomerInfo();

            // Restore input stream
            std::cin.rdbuf(prevCin);

            // Assert the expected values
            Assert::AreEqual(std::string("John"), std::string(customer.firstName));
            Assert::AreEqual(std::string("Smith"), std::string(customer.lastName));
            Assert::AreEqual(std::string("35 Elm St."), std::string(customer.streetAddress));
            Assert::AreEqual(std::string("Toronto"), std::string(customer.city));
            Assert::AreEqual(std::string("ON"), std::string(customer.province));
            Assert::AreEqual(std::string("M2E 4X4"), std::string(customer.postalCode));
        }
    };
}

