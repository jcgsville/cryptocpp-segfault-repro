// #include <cryptopp/hex.h>
// #include <cryptopp/hmac.h>
// #include <cryptopp/sha.h>
// #include <iostream>
// #include <string>
// #include <vector>

// int main() {
//   std::cout << "Starting HMAC test..." << std::endl;

//   try {
//     const std::string signing_key_str = "test-signing-key-12345";
//     const std::string message_str = "test-message";

//     // Convert to byte vectors (CryptoPP::byte is just unsigned char)
//     std::vector<CryptoPP::byte> signing_key(signing_key_str.begin(),
//                                             signing_key_str.end());
//     std::vector<CryptoPP::byte> message(message_str.begin(), message_str.end());

//     std::cout << "About to create HMAC object..." << std::endl;
//     CryptoPP::HMAC<CryptoPP::SHA256> hmac;
//     std::cout << "HMAC object created successfully" << std::endl;

//     std::cout << "About to set HMAC key..." << std::endl;
//     hmac.SetKey(signing_key.data(), signing_key.size());
//     std::cout << "HMAC key set successfully" << std::endl;

//     std::cout << "About to call hmac.Update()..." << std::endl;
//     hmac.Update(message.data(), message.size());
//     std::cout << "hmac.Update() completed successfully" << std::endl;
//     return 0;
//   } catch (const std::exception &e) {
//     std::cerr << "Exception occurred: " << e.what() << std::endl;
//     return 1;
//   } catch (...) {
//     std::cerr << "Unknown exception occurred" << std::endl;
//     return 1;
//   }
// }

#include <cryptopp/hex.h>
#include <cryptopp/hmac.h>
#include <cryptopp/sha.h>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::cout << "Starting HMAC test v3..." << std::endl;

  try {
    const std::string signing_key_str = "test-signing-key-12345";
    const std::string message_str = "test-message";

    // Convert to byte vectors (CryptoPP::byte is just unsigned char)
    std::vector<CryptoPP::byte> signing_key(signing_key_str.begin(), signing_key_str.end());
    std::vector<CryptoPP::byte> message(message_str.begin(), message_str.end());

    std::cout << "About to create HMAC object..." << std::endl;
    CryptoPP::HMAC<CryptoPP::SHA256> hmac;
    std::cout << "HMAC object created successfully" << std::endl;

    std::cout << "About to set HMAC key..." << std::endl;
    hmac.SetKey(signing_key.data(), signing_key.size());
    std::cout << "HMAC key set successfully" << std::endl;

    std::cout << "About to call hmac.Update()..." << std::endl;
    hmac.Update(message.data(), message.size());
    std::cout << "hmac.Update() completed successfully" << std::endl;

    std::cout << "About to allocate mac buffer..." << std::endl;
    std::vector<CryptoPP::byte> mac(hmac.DigestSize());
    std::cout << "mac buffer allocated successfully" << std::endl;

    std::cout << "About to call hmac.Final()..." << std::endl;
    hmac.Final(mac.data());
    std::cout << "hmac.Final() completed successfully" << std::endl;

    std::cout << "About to convert to hex..." << std::endl;
    CryptoPP::HexEncoder encoder;
    encoder.Put(mac.data(), mac.size());
    encoder.MessageEnd();

    CryptoPP::word64 size = encoder.MaxRetrievable();
    std::cout << "Hex encoder size: " << size << std::endl;

    if (size > 0) {
      std::string computed_signature(size, '\0');
      encoder.Get(reinterpret_cast<CryptoPP::byte*>(&computed_signature[0]), size);
      std::cout << "Hex conversion completed successfully" << std::endl;
      std::cout << "Computed signature: " << computed_signature << std::endl;
    }

    std::cout << "All HMAC operations completed successfully!" << std::endl;
    return 0;

  } catch (const std::exception &e) {
    std::cerr << "Exception occurred: " << e.what() << std::endl;
    return 1;
  } catch (...) {
    std::cerr << "Unknown exception occurred" << std::endl;
    return 1;
  }
}