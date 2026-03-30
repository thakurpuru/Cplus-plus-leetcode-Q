class Calculator {
    
    /** 
     * @param {number} value
     */
    
    constructor(value) {
        this.a=value;
    }
    
    /** 
     * @param {number} value
     * @return {Calculator}
     */
    add(value){
        this.a+=value;
        return this;
    }
    
    /** 
     * @param {number} value
     * @return {Calculator}
     */
    subtract(value){
        this.a-=value;
        return this;
    }
    
    /** 
     * @param {number} value
     * @return {Calculator}
     */  
    multiply(value) {
        this.a*=value;
        return this;
    }
    
    /** 
     * @param {number} value
     * @return {Calculator}
     */
    divide(value) {
        if(value==0){
            throw "Division by zero is not allowed";
        }
        this.a/=value;
        return this;
    }
    
    /** 
     * @param {number} value
     * @return {Calculator}
     */
    power(value) {
        this.a=this.a**value;
        return this;
    }
    
    /** 
     * @return {number}
     */
    getResult() {
        return this.a;
    }
}