#pragma once

#include <optional>
#include <stdexcept>
#include <regex>

/*
 * auth.LoginService
 */
class ApifoxModel {
    public:
    ApifoxModel() :
        field_constraint(std::nullopt, std::nullopt, 1, 32, std::nullopt),
        password_constraint(std::nullopt, std::nullopt, 6, 32, std::nullopt)
    {}
    virtual ~ApifoxModel() = default;

    private:
    std::string field;
    ClassMemberConstraints field_constraint;
    std::shared_ptr<bool> is_with_api_key;
    std::string password;
    ClassMemberConstraints password_constraint;

    public:
    const std::string & get_field() const { return field; }
    std::string & get_mutable_field() { return field; }
    void set_field(const std::string & value) { CheckConstraint("field", field_constraint, value); this->field = value; }

    /*
     * 是否带APIKey返回
     */
    std::shared_ptr<bool> get_is_with_api_key() const { return is_with_api_key; }
    void set_is_with_api_key(std::shared_ptr<bool> value) { this->is_with_api_key = value; }

    const std::string & get_password() const { return password; }
    std::string & get_mutable_password() { return password; }
    void set_password(const std::string & value) { CheckConstraint("password", password_constraint, value); this->password = value; }
};

